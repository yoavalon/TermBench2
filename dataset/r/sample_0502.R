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
        score = function(a, b) {
            if (a == b) {
                return(.self$match)
            } else {
                return(.self$mismatch)
            }
        },
        calculate_scores = function() {
            m <- nchar(.self$seq1)
            n <- nchar(.self$seq2)
            matrix <- matrix(0, nrow = m + 1, ncol = n + 1)
            for (i in 1:m) {
                for (j in 1:n) {
                    diagonal <- matrix[i, j] + .self$score(substr(.self$seq1, i, i), substr(.self$seq2, j, j))
                    up <- matrix[i, j + 1] + .self$gap
                    left <- matrix[i + 1, j] + .self$gap
                    matrix[i + 1, j + 1] <- max(diagonal, up, left)
                }
            }
            return(matrix)
        },
        trace_back = function(matrix) {
            m <- nchar(.self$seq1)
            n <- nchar(.self$seq2)
            aligned_seq1 <- ""
            aligned_seq2 <- ""
            while (m > 0 || n > 0) {
                if (m > 0 && n > 0 && matrix[m + 1, n + 1] == matrix[m, n] + .self$score(substr(.self$seq1, m, m), substr(.self$seq2, n, n))) {
                    aligned_seq1 <- paste0(substr(.self$seq1, m, m), aligned_seq1)
                    aligned_seq2 <- paste0(substr(.self$seq2, n, n), aligned_seq2)
                    m <- m - 1
                    n <- n - 1
                } else if (m > 0 && matrix[m + 1, n + 1] == matrix[m, n + 1] + .self$gap) {
                    aligned_seq1 <- paste0(substr(.self$seq1, m, m), aligned_seq1)
                    aligned_seq2 <- paste0("-", aligned_seq2)
                    m <- m - 1
                } else if (n > 0) {
                    aligned_seq1 <- paste0("-", aligned_seq1)
                    aligned_seq2 <- paste0(substr(.self$seq2, n, n), aligned_seq2)
                    n <- n - 1
                }
            }
            return(list(aligned_seq1, aligned_seq2))
        }
    )
)

main <- function() {
    seq1 <- "AGGTAB"
    seq2 <- "GXTXAYB"
    aligner <- SequenceAligner$new(seq1, seq2)
    scores <- aligner$calculate_scores()
    result <- aligner$trace_back(scores)
    cat("Aligned Seq 1:", result[[1]], "\n")
    cat("Aligned Seq 2:", result[[2]], "\n")
}

main()