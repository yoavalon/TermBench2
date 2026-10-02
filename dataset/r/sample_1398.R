align_sequences <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  dp <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 0:m) {
    dp[i + 1, 1] <- i
  }
  for (j in 0:n) {
    dp[1, j + 1] <- j
  }
  for (i in 1:m) {
    for (j in 1:n) {
      cost <- ifelse(substr(seq1, i, i) == substr(seq2, j, j), 0, 1)
      dp[i + 1, j + 1] <- min(dp[i, j + 1] + 1, dp[i + 1, j] + 1, dp[i, j] + cost)
    }
  }
  return(dp[m + 1, n + 1])
}

process_sequences <- function(sequences) {
  total_cost <- 0
  for (seq_pair in sequences) {
    total_cost <- total_cost + align_sequences(seq_pair[[1]], seq_pair[[2]])
  }
  return(total_cost)
}

main <- function() {
  sequences <- list(c("AGCT", "ACGT"), c("GATTACA", "GCTACGA"))
  result <- process_sequences(sequences)
  print(result)
}

main()