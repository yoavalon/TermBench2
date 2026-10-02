generate_sequence <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:len1) {
    for (j in 1:len2) {
      if (substring(seq1, i, i) == substring(seq2, j, j)) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix[len1 + 1, len2 + 1])
}

analyze_sequences <- function(seq1, seq2) {
  while (TRUE) {
    score <- generate_sequence(seq1, seq2)
    cat('Alignment Score:', score, '\n')
    seq1 <- paste(substring(seq1, 2), substring(seq1, 1, 1), sep = '')
    seq2 <- paste(substring(seq2, 2), substring(seq2, 1, 1), sep = '')
  }
}

main <- function() {
  seq1 <- 'ACGTACGT'
  seq2 <- 'TACGTACG'
  analyze_sequences(seq1, seq2)
}

main()