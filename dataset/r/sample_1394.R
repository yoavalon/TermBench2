align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  dp <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  
  for (i in 0:(len1 + 1)) {
    for (j in 0:(len2 + 1)) {
      if (i == 0 || j == 0) {
        dp[i + 1, j + 1] <- 0
      } else if (substring(seq1, i, i) == substring(seq2, j, j)) {
        dp[i + 1, j + 1] <- dp[i, j] + 1
      } else {
        dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j])
      }
    }
  }
  return(dp[len1 + 1, len2 + 1])
}

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  result <- align_sequences(seq1, seq2)
  cat('Longest Common Subsequence length:', result, '\n')
}

main()