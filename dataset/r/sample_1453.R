SequenceAligner <- R6::R6Class("SequenceAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    traceback = NULL,
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
      self$traceback <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    fill_matrix = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          match <- self$matrix[i, j] + (substr(self$seq1, i, i) == substr(self$seq2, j, j))
          delete <- self$matrix[i, j + 1] - 1
          insert <- self$matrix[i + 1, j] - 1
          self$matrix[i + 1, j + 1] <- max(match, delete, insert)
          if (self$matrix[i + 1, j + 1] == match) {
            self$traceback[i + 1, j + 1] <- 1
          } else if (self$matrix[i + 1, j + 1] == delete) {
            self$traceback[i + 1, j + 1] <- 2
          } else {
            self$traceback[i + 1, j + 1] <- 3
          }
        }
      }
    },
    align_sequences = function() {
      aligned_seq1 <- ""
      aligned_seq2 <- ""
      i <- nchar(self$seq1)
      j <- nchar(self$seq2)
      while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && self$traceback[i + 1, j + 1] == 1) {
          aligned_seq1 <- substr(self$seq1, i, i) %>% paste(aligned_seq1)
          aligned_seq2 <- substr(self$seq2, j, j) %>% paste(aligned_seq2)
          i <- i - 1
          j <- j - 1
        } else if (i > 0 && (j == 0 || self$traceback[i + 1, j + 1] == 2)) {
          aligned_seq1 <- substr(self$seq1, i, i) %>% paste(aligned_seq1)
          aligned_seq2 <- "-" %>% paste(aligned_seq2)
          i <- i - 1
        } else {
          aligned_seq1 <- "-" %>% paste(aligned_seq1)
          aligned_seq2 <- substr(self$seq2, j, j) %>% paste(aligned_seq2)
          j <- j - 1
        }
      }
      return(list(aligned_seq1, aligned_seq2))
    }
  )
)

main <- function() {
  seq1 <- "GATTACA"
  seq2 <- "CGATTACG"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$fill_matrix()
  result <- aligner$align_sequences()
  print(result[[1]])
  print(result[[2]])
}

main()