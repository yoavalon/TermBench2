compute_similarity <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:len1) {
    for (j in 1:len2) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix[len1 + 1, len2 + 1])
}

generate_sequences <- function() {
  seq1 <- "ACGT"
  seq2 <- "ACGTC"
  repeat {
    yield <- list(seq1, seq2)
    seq1 <- paste0(seq1, "A")
    seq2 <- paste0(seq2, "C")
    yield
  }
}

main <- function() {
  for (seq_pair in generate_sequences()) {
    seq1 <- seq_pair[[1]]
    seq2 <- seq_pair[[2]]
    similarity <- compute_similarity(seq1, seq2)
    cat(paste0("Similarity between ", seq1, " and ", seq2, ": ", similarity, "\n"))
  }
}

main()