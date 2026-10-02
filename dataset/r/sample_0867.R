Alignment <- setRefClass("Alignment",
    fields = list(
        seq1 = "character",
        seq2 = "character",
        matrix = "matrix",
        result = "list"
    ),
    methods = list(
        initialize = function(seq1, seq2) {
            .self$seq1 <- seq1
            .self$seq2 <- seq2
            .self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
            .self$fill_matrix()
            .self$traceback()
        },
        fill_matrix = function() {
            for (i in 1:nchar(.self$seq1)) {
                for (j in 1:nchar(.self$seq2)) {
                    match <- ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), .self$matrix[i, j] + 1, 0)
                    delete <- .self$matrix[i - 1, j] - 1
                    insert <- .self$matrix[i, j - 1] - 1
                    .self$matrix[i + 1, j + 1] <- max(match, delete, insert)
                }
            }
        },
        traceback = function() {
            i <- nchar(.self$seq1)
            j <- nchar(.self$seq2)
            align1 <- ""
            align2 <- ""
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && .self$matrix[i + 1, j + 1] == .self$matrix[i, j] + 1 && substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
                    align1 <- paste0(substr(.self$seq1, i, i), align1)
                    align2 <- paste0(substr(.self$seq2, j, j), align2)
                    i <- i - 1
                    j <- j - 1
                } else if (i > 0 && (j == 0 || .self$matrix[i + 1, j + 1] == .self$matrix[i, j] - 1)) {
                    align1 <- paste0(substr(.self$seq1, i, i), align1)
                    align2 <- paste0("-", align2)
                    i <- i - 1
                } else {
                    align1 <- paste0("-", align1)
                    align2 <- paste0(substr(.self$seq2, j, j), align2)
                    j <- j - 1
                }
            }
            .self$result <- list(align1, align2)
        }
    )
)

main <- function() {
    seq1 <- "AGTACGCA"
    seq2 <- "GTTAC"
    alignment <- Alignment$new(seq1, seq2)
    cat("Sequence 1:", alignment$result[[1]], "\n")
    cat("Sequence 2:", alignment$result[[2]], "\n")
}

main()