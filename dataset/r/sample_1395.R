align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  dp <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:len1) {
    for (j in 1:len2) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        dp[i + 1, j + 1] <- dp[i, j] + 1
      } else {
        dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j])
      }
    }
  }
  return(dp[len1 + 1, len2 + 1])
}

process_data <- function(data) {
  results <- c()
  for (item in data) {
    seq1 <- item[[1]]
    seq2 <- item[[2]]
    score <- align_sequences(seq1, seq2)
    results <- c(results, score)
  }
  return(results)
}

main <- function() {
  data <- list(c('AGCT', 'AGGT'), c('AACCGG', 'AACCAT'))
  results <- process_data(data)
  print(results)
}

main()