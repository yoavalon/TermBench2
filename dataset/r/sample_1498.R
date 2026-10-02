SequenceMatcher <- R6::R6Class("SequenceMatcher",
  public = list(
    seq1 = NULL,
    seq2 = NULL,
    matrix = NULL,
    
    initialize = function(seq1, seq2) {
      self$seq1 <- seq1
      self$seq2 <- seq2
      self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    
    compute_alignment = function() {
      for (i in 1:nchar(self$seq1)) {
        for (j in 1:nchar(self$seq2)) {
          match <- ifelse(substr(self$seq1, i, i) == substr(self$seq2, j, j), self$matrix[i, j] + 1, 0)
          delete <- self$matrix[i, j + 1]
          insert <- self$matrix[i + 1, j]
          self$matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    
    trace_back = function() {
      alignment1 <- ""
      alignment2 <- ""
      i <- nchar(self$seq1)
      j <- nchar(self$seq2)
      while (i > 0 && j > 0) {
        if (substr(self$seq1, i, i) == substr(self$seq2, j, j)) {
          alignment1 <- paste0(substr(self$seq1, i, i), alignment1)
          alignment2 <- paste0(substr(self$seq2, j, j), alignment2)
          i <- i - 1
          j <- j - 1
        } else if (self$matrix[i, j + 1] >= self$matrix[i + 1, j]) {
          alignment1 <- paste0(substr(self$seq1, i, i), alignment1)
          alignment2 <- paste0("-", alignment2)
          i <- i - 1
        } else {
          alignment1 <- paste0("-", alignment1)
          alignment2 <- paste0(substr(self$seq2, j, j), alignment2)
          j <- j - 1
        }
      }
      while (i > 0) {
        alignment1 <- paste0(substr(self$seq1, i, i), alignment1)
        alignment2 <- paste0("-", alignment2)
        i <- i - 1
      }
      while (j > 0) {
        alignment1 <- paste0("-", alignment1)
        alignment2 <- paste0(substr(self$seq2, j, j), alignment2)
        j <- j - 1
      }
      return(list(alignment1, alignment2))
    }
  )
)

process_sequences <- function(seq1, seq2) {
  matcher <- SequenceMatcher$new(seq1, seq2)
  matcher$compute_alignment()
  return(matcher$trace_back())
}

main <- function() {
  seq1 <- "AGCTG"
  seq2 <- "AGGCT"
  aligned_seq1 <- process_sequences(seq1, seq2)[[1]]
  aligned_seq2 <- process_sequences(seq1, seq2)[[2]]
  print(aligned_seq1)
  print(aligned_seq2)
}

main()