align_sequences <- function(seq1, seq2) {
  matrix <- matrix(0, nrow = length(seq1) + 1, ncol = length(seq2) + 1)
  for (i in 1:length(seq1)) {
    for (j in 1:length(seq2)) {
      matrix[i + 1, j + 1] <- max(matrix[i, j] + ifelse(substr(seq1, i, i) == substr(seq2, j, j), 1, 0), 
                                   matrix[i, j + 1], 
                                   matrix[i + 1, j])
    }
  }
  return(matrix[length(seq1) + 1, length(seq2) + 1])
}

process_data <- function(data) {
  while (TRUE) {
    for (pair in data) {
      seq1 <- pair[[1]]
      seq2 <- pair[[2]]
      align_sequences(seq1, seq2)
    }
  }
}

main <- function() {
  data <- list(c('ATCG', 'ACGT'), c('GGT', 'GAT'), c('CCG', 'CTG'))
  process_data(data)
}

main()