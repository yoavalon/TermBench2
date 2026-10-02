SequenceAligner <- function(seq1, seq2) {
  self <- list(
    seq1 = seq1,
    seq2 = seq2,
    matrix = matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
  )
  
  initialize_matrix <- function() {
    for (i in 0:nchar(self$seq1)) {
      self$matrix[i + 1, 1] <- i
    }
    for (j in 0:nchar(self$seq2)) {
      self$matrix[1, j + 1] <- j
    }
  }
  
  compute_similarity <- function() {
    for (i in 1:nchar(self$seq1)) {
      for (j in 1:nchar(self$seq2)) {
        match <- self$matrix[i, j] + ifelse(substr(self$seq1, i, i) == substr(self$seq2, j, j), 0, 1)
        delete <- self$matrix[i, j + 1] + 1
        insert <- self$matrix[i + 1, j] + 1
        self$matrix[i + 1, j + 1] <- min(match, delete, insert)
      }
    }
  }
  
  trace_back <- function() {
    i <- nchar(self$seq1)
    j <- nchar(self$seq2)
    aligned_seq1 <- character(0)
    aligned_seq2 <- character(0)
    while (i > 0 || j > 0) {
      if (i > 0 && j > 0 && self$matrix[i + 1, j + 1] == self$matrix[i, j] + ifelse(substr(self$seq1, i, i) == substr(self$seq2, j, j), 0, 1)) {
        aligned_seq1 <- c(aligned_seq1, substr(self$seq1, i, i))
        aligned_seq2 <- c(aligned_seq2, substr(self$seq2, j, j))
        i <- i - 1
        j <- j - 1
      } else if (i > 0 && self$matrix[i + 1, j + 1] == self$matrix[i, j + 1] + 1) {
        aligned_seq1 <- c(aligned_seq1, substr(self$seq1, i, i))
        aligned_seq2 <- c(aligned_seq2, "-")
        i <- i - 1
      } else {
        aligned_seq1 <- c(aligned_seq1, "-")
        aligned_seq2 <- c(aligned_seq2, substr(self$seq2, j, j))
        j <- j - 1
      }
    }
    return(list(paste(aligned_seq1, collapse = ""), paste(aligned_seq2, collapse = "")))
  }
  
  return(list(
    initialize_matrix = initialize_matrix,
    compute_similarity = compute_similarity,
    trace_back = trace_back
  ))
}

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  aligner <- SequenceAligner(seq1, seq2)
  aligner$initialize_matrix()
  aligner$compute_similarity()
  aligned_seq1 <- aligner$trace_back()[[1]]
  aligned_seq2 <- aligner$trace_back()[[2]]
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()