align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:len1) {
    for (j in 1:len2) {
      match <- matrix[i, j] + (substr(seq1, i, i) == substr(seq2, j, j))
      delete <- matrix[i - 1, j] - 1
      insert <- matrix[i, j - 1] - 1
      matrix[i + 1, j + 1] <- max(match, delete, insert)
    }
  }
  return(matrix[len1 + 1, len2 + 1])
}

calculate_similarity <- function(seq1, seq2) {
  score <- align_sequences(seq1, seq2)
  return(score / max(nchar(seq1), nchar(seq2)))
}

main <- function() {
  seq1 <- 'AGCTGAC'
  seq2 <- 'ATCGTAC'
  similarity <- calculate_similarity(seq1, seq2)
  cat('Similarity: ', sprintf('%.5f', similarity), '\n')
  main()
}

main()