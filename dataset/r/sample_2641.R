SequenceAligner <- setRefClass("SequenceAligner",
                              fields = list(seq1 = "character", seq2 = "character", matrix = "matrix"),
                              methods = list(
    initialize = function(seq1, seq2) {
        seq1 <<- seq1
        seq2 <<- seq2
        matrix <<- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    fill_matrix = function() {
        for (i in 1:nchar(seq1)) {
            for (j in 1:nchar(seq2)) {
                match <- ifelse(substr(seq1, i, i) == substr(seq2, j, j), matrix[i, j] + 1, 0)
                delete <- matrix[i - 1, j] - 1
                insert <- matrix[i, j - 1] - 1
                matrix[i + 1, j + 1] <<- max(match, delete, insert)
            }
        }
    },
    trace_back = function() {
        i <- nchar(seq1)
        j <- nchar(seq2)
        aligned_seq1 <- c()
        aligned_seq2 <- c()
        while (i > 0 && j > 0) {
            if (substr(seq1, i, i) == substr(seq2, j, j)) {
                aligned_seq1 <<- c(aligned_seq1, substr(seq1, i, i))
                aligned_seq2 <<- c(aligned_seq2, substr(seq2, j, j))
                i <<- i - 1
                j <<- j - 1
            } else if (matrix[i, j + 1] > matrix[i + 1, j]) {
                aligned_seq1 <<- c(aligned_seq1, substr(seq1, i, i))
                aligned_seq2 <<- c(aligned_seq2, "-")
                i <<- i - 1
            } else {
                aligned_seq1 <<- c(aligned_seq1, "-")
                aligned_seq2 <<- c(aligned_seq2, substr(seq2, j, j))
                j <<- j - 1
            }
        }
        aligned_seq1 <<- rev(aligned_seq1)
        aligned_seq2 <<- rev(aligned_seq2)
        return(list(paste(aligned_seq1, collapse = ""), paste(aligned_seq2, collapse = "")))
    }
))

main <- function() {
    seq1 <- "GATTACA"
    seq2 <- "CGATACG"
    aligner <- SequenceAligner(seq1 = seq1, seq2 = seq2)
    aligner$fill_matrix()
    result <- aligner$trace_back()
    cat(result[[1]], "\n")
    cat(result[[2]], "\n")
}

main()