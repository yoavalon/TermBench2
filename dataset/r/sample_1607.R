align_sequences <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  dp <- matrix(0, nrow = m + 1, ncol = n + 1)
  for (i in 0:(m + 1)) {
    for (j in 0:(n + 1)) {
      if (i == 0 || j == 0) {
        dp[i + 1, j + 1] <- 0
      } else if (substr(seq1, i, i) == substr(seq2, j, j)) {
        dp[i + 1, j + 1] <- dp[i, j] + 1
      } else {
        dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j])
      }
    }
  }
  return(dp[m + 1, n + 1])
}

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  while (TRUE) {
    result <- align_sequences(seq1, seq2)
    print(result)
  }
}

main()