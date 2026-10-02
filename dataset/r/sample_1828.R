process_sequences <- function(seq1, seq2) {
  align_matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
  for (i in 1:nchar(seq1)) {
    for (j in 1:nchar(seq2)) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        match <- align_matrix[i, j] + 1
      } else {
        match <- 0
      }
      align_matrix[i + 1, j + 1] <- max(align_matrix[i + 1, j], align_matrix[i, j + 1], match)
    }
  }
  return(align_matrix[nchar(seq1) + 1, nchar(seq2) + 1])
}

main <- function() {
  seq1 <- "ACGT"
  seq2 <- "ACCGT"
  result <- process_sequences(seq1, seq2)
  print(result)
}

main()