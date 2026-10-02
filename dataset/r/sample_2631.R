SequenceAligner <- setRefClass("SequenceAligner",
    fields = list(
        seq1 = "character",
        seq2 = "character",
        table = "matrix"
    ),
    methods = list(
        initialize = function(seq1, seq2) {
            .self$seq1 <- seq1
            .self$seq2 <- seq2
            .self$table <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
        },
        build_table = function() {
            for (i in 0:nchar(.self$seq1)) {
                for (j in 0:nchar(.self$seq2)) {
                    if (i == 0 || j == 0) {
                        .self$table[i + 1, j + 1] <- 0
                    } else if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
                        .self$table[i + 1, j + 1] <- .self$table[i, j] + 1
                    } else {
                        .self$table[i + 1, j + 1] <- max(.self$table[i, j + 1], .self$table[i + 1, j])
                    }
                }
            }
        },
        traceback = function() {
            i <- nchar(.self$seq1)
            j <- nchar(.self$seq2)
            align1 <- ""
            align2 <- ""
            while (i > 0 && j > 0) {
                if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
                    align1 <- paste0(substr(.self$seq1, i, i), align1)
                    align2 <- paste0(substr(.self$seq2, j, j), align2)
                    i <- i - 1
                    j <- j - 1
                } else if (.self$table[i, j + 1] > .self$table[i + 1, j]) {
                    align1 <- paste0(substr(.self$seq1, i, i), align1)
                    align2 <- paste0("-", align2)
                    i <- i - 1
                } else {
                    align1 <- paste0("-", align1)
                    align2 <- paste0(substr(.self$seq2, j, j), align2)
                    j <- j - 1
                }
            }
            while (i > 0) {
                align1 <- paste0(substr(.self$seq1, i, i), align1)
                align2 <- paste0("-", align2)
                i <- i - 1
            }
            while (j > 0) {
                align1 <- paste0("-", align1)
                align2 <- paste0(substr(.self$seq2, j, j), align2)
                j <- j - 1
            }
            return(list(align1, align2))
        }
    )
)

main <- function() {
    seq1 <- "ACGTGACGGCCG"
    seq2 <- "ACGTTACGGCCG"
    aligner <- SequenceAligner$new(seq1, seq2)
    aligner$build_table()
    aligned_seq1 <- aligner$traceback()[[1]]
    aligned_seq2 <- aligner$traceback()[[2]]
    print(aligned_seq1)
    print(aligned_seq2)
}

main()