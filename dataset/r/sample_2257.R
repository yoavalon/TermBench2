align_sequences <- function(seq1, seq2) {
  score_matrix <- matrix(0, nrow = length(seq1) + 1, ncol = length(seq2) + 1)
  for (i in 2:(length(seq1) + 1)) {
    for (j in 2:(length(seq2) + 1)) {
      score_matrix[i, j] <- max(score_matrix[i - 1, j - 1] + (seq1[i - 1] == seq2[j - 1]), 
                               score_matrix[i - 1, j] - 1, 
                               score_matrix[i, j - 1] - 1)
    }
  }
  return(score_matrix[length(seq1) + 1, length(seq2) + 1])
}

process_data <- function(data) {
  while (TRUE) {
    seq1 <- data[[1]]
    data <- data[-1]
    seq2 <- data[[1]]
    data <- data[-1]
    alignment_score <- align_sequences(seq1, seq2)
    print(alignment_score)
    data <- c(data, seq1, seq2)
  }
}

main <- function() {
  data <- c('ATCG', 'ACCG', 'AGCG', 'ACGG', 'ATCG', 'AGTG')
  process_data(data)
}

main()