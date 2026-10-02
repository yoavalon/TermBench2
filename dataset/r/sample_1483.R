SequenceAligner <- R6::R6Class("SequenceAligner",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    score_matrix = NULL,
    traceback_matrix = NULL,
    max_score = 0,
    max_position = c(0, 0),
    
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$score_matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
      self$traceback_matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
      self$max_score <- 0
      self$max_position <- c(0, 0)
    },
    
    initialize_matrices = function() {
      len1 <- nchar(self$seq1)
      len2 <- nchar(self$seq2)
      for (i in 1:(len1 + 1)) {
        for (j in 1:(len2 + 1)) {
          self$score_matrix[i, j] <- 0
          self$traceback_matrix[i, j] <- 0
        }
      }
    },
    
    fill_matrices = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          match <- self$score_matrix[i, j] + ifelse(substr(self$seq1, i, i) == substr(self$seq2, j, j), 1, -1)
          delete <- self$score_matrix[i, j + 1] - 1
          insert <- self$score_matrix[i + 1, j] - 1
          self$score_matrix[i + 1, j + 1] <- max(match, delete, insert)
          if (self$score_matrix[i + 1, j + 1] == match) {
            self$traceback_matrix[i + 1, j + 1] <- 1
          } else if (self$score_matrix[i + 1, j + 1] == delete) {
            self$traceback_matrix[i + 1, j + 1] <- 2
          } else {
            self$traceback_matrix[i + 1, j + 1] <- 3
          }
          if (self$score_matrix[i + 1, j + 1] > self$max_score) {
            self$max_score <- self$score_matrix[i + 1, j + 1]
            self$max_position <- c(i + 1, j + 1)
          }
        }
      }
    },
    
    backtrack = function() {
      aligned_seq1 <- character(0)
      aligned_seq2 <- character(0)
      i <- self$max_position[1]
      j <- self$max_position[2]
      while (i > 0 && j > 0) {
        if (self$traceback_matrix[i, j] == 1) {
          aligned_seq1 <- c(substr(self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- c(substr(self$seq2, j, j), aligned_seq2)
          i <- i - 1
          j <- j - 1
        } else if (self$traceback_matrix[i, j] == 2) {
          aligned_seq1 <- c(substr(self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- c("-", aligned_seq2)
          i <- i - 1
        } else {
          aligned_seq1 <- c("-", aligned_seq1)
          aligned_seq2 <- c(substr(self$seq2, j, j), aligned_seq2)
          j <- j - 1
        }
      }
      return(c(paste(aligned_seq1, collapse = ""), paste(aligned_seq2, collapse = "")))
    }
  )
)

main <- function() {
  seq1 <- "AGCTG"
  seq2 <- "CGTAT"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$initialize_matrices()
  aligner$fill_matrices()
  aligned_seq1 <- aligner$backtrack()[1]
  aligned_seq2 <- aligner$backtrack()[2]
  print(aligned_seq1)
  print(aligned_seq2)
}

main()