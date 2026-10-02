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
            .self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
        },
        fill_matrix = function() {
            for (i in 1:nchar(.self$seq1)) {
                for (j in 1:nchar(.self$seq2)) {
                    match <- ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), .self$matrix[i, j] + 1, 0)
                    .self$matrix[i + 1, j + 1] <- max(.self$matrix[i, j + 1], .self$matrix[i + 1, j], match)
                }
            }
        },
        traceback = function() {
            aligned_seq1 <- character()
            aligned_seq2 <- character()
            i <- nchar(.self$seq1)
            j <- nchar(.self$seq2)
            while (i > 0 | j > 0) {
                if (i > 0 & j > 0 & substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
                    aligned_seq1 <- c(substr(.self$seq1, i, i), aligned_seq1)
                    aligned_seq2 <- c(substr(.self$seq2, j, j), aligned_seq2)
                    i <- i - 1
                    j <- j - 1
                } else if (i > 0 & .self$matrix[i + 1, j + 1] == .self$matrix[i, j + 1]) {
                    aligned_seq1 <- c(substr(.self$seq1, i, i), aligned_seq1)
                    aligned_seq2 <- c('-', aligned_seq2)
                    i <- i - 1
                } else {
                    aligned_seq1 <- c('-', aligned_seq1)
                    aligned_seq2 <- c(substr(.self$seq2, j, j), aligned_seq2)
                    j <- j - 1
                }
            }
            return(list(paste(aligned_seq1, collapse = ""), paste(aligned_seq2, collapse = "")))
        }
    )
)

main <- function() {
    seq1 <- "AGGTAB"
    seq2 <- "GXTXAYB"
    aligner <- SequenceAligner$new(seq1, seq2)
    aligner$fill_matrix()
    aligned_seq1 <- aligner$traceback()[[1]]
    aligned_seq2 <- aligner$traceback()[[2]]
    cat(aligned_seq1, "\n")
    cat(aligned_seq2, "\n")
}

main()