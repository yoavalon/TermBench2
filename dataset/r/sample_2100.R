SequenceAligner <- R6::R6Class("SequenceAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    traceback_matrix = NULL,
    
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
      self$traceback_matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    
    initialize_matrices = function() {
      m <- nchar(self$seq1) + 1
      n <- nchar(self$seq2) + 1
      for (i in 1:m) {
        self$matrix[i, 1] <- i
        self$traceback_matrix[i, 1] <- 1
      }
      for (j in 1:n) {
        self$matrix[1, j] <- j
        self$traceback_matrix[1, j] <- 2
      }
    },
    
    fill_matrices = function() {
      m <- nchar(self$seq1)
      n <- nchar(self$seq2)
      for (i in 1:m) {
        for (j in 1:n) {
          match <- self$matrix[i, j] + (substr(self$seq1, i, i) == substr(self$seq2, j, j))
          delete <- self$matrix[i, j + 1] + 1
          insert <- self$matrix[i + 1, j] + 1
          self$matrix[i + 1, j + 1] <- min(match, delete, insert)
          if (self$matrix[i + 1, j + 1] == match) {
            self$traceback_matrix[i + 1, j + 1] <- 3
          } else if (self$matrix[i + 1, j + 1] == delete) {
            self$traceback_matrix[i + 1, j + 1] <- 1
          } else {
            self$traceback_matrix[i + 1, j + 1] <- 2
          }
        }
      }
    },
    
    traceback = function() {
      alignment1 <- ""
      alignment2 <- ""
      i <- nchar(self$seq1)
      j <- nchar(self$seq2)
      while (i > 0 || j > 0) {
        if (self$traceback_matrix[i + 1, j + 1] == 3) {
          alignment1 <- substr(self$seq1, i, i) %>% paste(alignment1, sep = "")
          alignment2 <- substr(self$seq2, j, j) %>% paste(alignment2, sep = "")
          i <- i - 1
          j <- j - 1
        } else if (self$traceback_matrix[i + 1, j + 1] == 1) {
          alignment1 <- substr(self$seq1, i, i) %>% paste(alignment1, sep = "")
          alignment2 <- "-" %>% paste(alignment2, sep = "")
          i <- i - 1
        } else {
          alignment1 <- "-" %>% paste(alignment1, sep = "")
          alignment2 <- substr(self$seq2, j, j) %>% paste(alignment2, sep = "")
          j <- j - 1
        }
      }
      return(list(alignment1, alignment2))
    }
  )
)

main <- function() {
  seq1 <- "GATTACA"
  seq2 <- "GCATGCU"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$initialize_matrices()
  aligner$fill_matrices()
  result <- aligner$traceback()
  cat(result[[1]], "\n")
  cat(result[[2]], "\n")
}

main()