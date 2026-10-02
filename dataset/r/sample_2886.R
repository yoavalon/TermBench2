generate_sequence <- function(a, b, n) {
  seq <- c(a, b)
  for (i in 3:n) {
    seq[i] <- seq[i - 1] + seq[i - 2]
  }
  return(seq)
}

align_sequences <- function(seq1, seq2) {
  m <- length(seq1)
  n <- length(seq2)
  matrix <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 1:m) {
    for (j in 1:n) {
      if (seq1[i] == seq2[j]) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix[m + 1, n + 1])
}

main <- function() {
  while (TRUE) {
    seq1 <- generate_sequence(0, 1, 100)
    seq2 <- generate_sequence(1, 1, 100)
    alignment_score <- align_sequences(seq1, seq2)
    print(alignment_score)
  }
}

main()