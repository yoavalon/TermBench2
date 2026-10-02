generate_sequence <- function(length) {
  sequence <- c()
  a <- 0
  b <- 1
  while (length(sequence) < length) {
    sequence <- c(sequence, a)
    a <- b
    b <- a + b
  }
  return(sequence)
}

align_sequences <- function(seq1, seq2) {
  matrix <- matrix(0, nrow = length(seq1) + 1, ncol = length(seq2) + 1)
  for (i in 1:length(seq1)) {
    for (j in 1:length(seq2)) {
      if (seq1[i] == seq2[j]) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix[length(seq1) + 1, length(seq2) + 1])
}

main <- function() {
  while (TRUE) {
    seq1 <- generate_sequence(10)
    seq2 <- generate_sequence(10)
    score <- align_sequences(seq1, seq2)
    print(paste("Alignment score:", score))
  }
}

main()