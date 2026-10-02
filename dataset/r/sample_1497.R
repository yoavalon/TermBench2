SequenceAligner <- setRefClass("SequenceAligner",
    fields = list(
        seq1 = "character",
        seq2 = "character",
        matrix = "matrix"
    ),
    methods = list(
        initialize = function(seq1, seq2) {
            .self$seq1 <- seq1
            .self$seq2 <- seq2
            .self$matrix <- NULL
        },
        create_matrix = function() {
            .self$matrix <- matrix(0, nrow = nchar(.self$seq1) + 1, ncol = nchar(.self$seq2) + 1)
        },
        fill_matrix = function() {
            for (i in 1:nchar(.self$seq1)) {
                for (j in 1:nchar(.self$seq2)) {
                    match <- .self$matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, 0)
                    delete <- .self$matrix[i, j - 1] - 1
                    insert <- .self$matrix[i - 1, j] - 1
                    .self$matrix[i + 1, j + 1] <- max(match, delete, insert)
                }
            }
        },
        trace_back = function() {
            i <- nchar(.self$seq1)
            j <- nchar(.self$seq2)
            align1 <- c()
            align2 <- c()
            while (i > 0 & j > 0) {
                if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
                    align1 <- c(substr(.self$seq1, i, i), align1)
                    align2 <- c(substr(.self$seq2, j, j), align2)
                    i <- i - 1
                    j <- j - 1
                } else if (.self$matrix[i, j] > .self$matrix[i - 1, j]) {
                    align1 <- c(substr(.self$seq1, i, i), align1)
                    align2 <- c("-", align2)
                    i <- i - 1
                } else {
                    align1 <- c("-", align1)
                    align2 <- c(substr(.self$seq2, j, j), align2)
                    j <- j - 1
                }
            }
            while (i > 0) {
                align1 <- c(substr(.self$seq1, i, i), align1)
                align2 <- c("-", align2)
                i <- i - 1
            }
            while (j > 0) {
                align1 <- c("-", align1)
                align2 <- c(substr(.self$seq2, j, j), align2)
                j <- j - 1
            }
            return(list(paste(align1, collapse = ""), paste(align2, collapse = "")))
        }
    )
)

main <- function() {
    seq1 <- "GATTACA"
    seq2 <- "GCATGCU"
    aligner <- SequenceAligner$new(seq1, seq2)
    aligner$create_matrix()
    aligner$fill_matrix()
    aligned_seq <- aligner$trace_back()
    print(aligned_seq[[1]])
    print(aligned_seq[[2]])
}

main()