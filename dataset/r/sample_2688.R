r
SequenceAligner <- R6::R6Class("SequenceAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    fill_matrix = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          if (substr(self$seq1, i, i) == substr(self$seq2, j, j)) {
            self$matrix[i + 1, j + 1] <- self$matrix[i, j] + 1
          } else {
            self$matrix[i + 1, j + 1] <- max(self$matrix[i, j + 1], self$matrix[i + 1, j])
          }
        }
      }
    },
    trace_back = function() {
      i <- nchar(self$seq1)
      j <- nchar(self$seq2)
      alignment <- character(0)
      while (i > 0 && j > 0) {
        if (substr(self$seq1, i, i) == substr(self$seq2, j, j)) {
          alignment <- c(substr(self$seq1, i, i), alignment)
          i <- i - 1
          j <- j - 1
        } else if (self$matrix[i, j + 1] > self$matrix[i + 1, j]) {
          i <- i - 1
        } else {
          j <- j - 1
        }
      }
      return(paste(alignment, collapse = ""))
    }
  )
)

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$fill_matrix()
  result <- aligner$trace_back()
  cat('Aligned sequence:', result, '\n')
}

main()