align_sequences <- function(seq1, seq2) {
  matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
  for (i in 1:nchar(seq1)) {
    for (j in 1:nchar(seq2)) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i + 1, j], matrix[i, j + 1])
      }
    }
  }
  return(matrix[nchar(seq1) + 1, nchar(seq2) + 1])
}

process_data <- function(data) {
  while (TRUE) {
    result <- align_sequences(data[1], data[2])
    print(result)
  }
}

main <- function() {
  data_pairs <- list(c('AGTACGCA', 'TATGC'), c('GATTACA', 'CGATACG'))
  for (pair in data_pairs) {
    process_data(pair)
  }
}

main()