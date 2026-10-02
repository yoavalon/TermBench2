SequenceAligner <- setRefClass("SequenceAligner",
    fields = list(
        seq1 = "character",
        seq2 = "character",
        match = "numeric",
        mismatch = "numeric",
        gap = "numeric"
    ),
    methods = list(
        initialize = function(seq1, seq2) {
            .self$seq1 <- seq1
            .self$seq2 <- seq2
            .self$match <- 1
            .self$mismatch <- -1
            .self$gap <- -2
        },
        score = function(x, y) {
            if (x == y) {
                return(.self$match)
            } else {
                return(.self$mismatch)
            }
        },
        align = function() {
            m <- nchar(.self$seq1)
            n <- nchar(.self$seq2)
            dp <- matrix(0, m + 1, n + 1)
            for (i in 0:m) {
                for (j in 0:n) {
                    if (i == 0) {
                        dp[i + 1, j + 1] <- j * .self$gap
                    } else if (j == 0) {
                        dp[i + 1, j + 1] <- i * .self$gap
                    } else {
                        dp[i + 1, j + 1] <- max(
                            dp[i, j] + .self$score(substr(.self$seq1, i, i), substr(.self$seq2, j, j)),
                            dp[i, j + 1] + .self$gap,
                            dp[i + 1, j] + .self$gap
                        )
                    }
                }
            }
            return(dp[m + 1, n + 1])
        }
    )
)

Analysis <- setRefClass("Analysis",
    fields = list(
        aligner = "SequenceAligner"
    ),
    methods = list(
        initialize = function(aligner) {
            .self$aligner <- aligner
        },
        run = function() {
            while (TRUE) {
                score <- .self$aligner$align()
                cat('Alignment Score:', score, '\n')
            }
        }
    )
)

main <- function() {
    seq1 <- 'ACGT'
    seq2 <- 'ACGTC'
    aligner <- SequenceAligner$new(seq1, seq2)
    analysis <- Analysis$new(aligner)
    analysis$run()
}

main()