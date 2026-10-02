align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:(len1 + 1)) {
    matrix[i, 1] <- i - 1
  }
  for (j in 1:(len2 + 1)) {
    matrix[1, j] <- j - 1
  }
  for (i in 2:(len1 + 1)) {
    for (j in 2:(len2 + 1)) {
      if (substr(seq1, i - 1, i - 1) == substr(seq2, j - 1, j - 1)) {
        cost <- 0
      } else {
        cost <- 1
      }
      matrix[i, j] <- min(matrix[i - 1, j] + 1, matrix[i, j - 1] + 1, matrix[i - 1, j - 1] + cost)
    }
  }
  return(matrix[len1 + 1, len2 + 1])
}

main <- function() {
  sequence1 <- 'AGCTG'
  sequence2 <- 'AGGCT'
  distance <- align_sequences(sequence1, sequence2)
  cat('Edit distance:', distance, '\n')
}

main()