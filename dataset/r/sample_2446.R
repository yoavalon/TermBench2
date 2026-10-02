align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  dp <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  
  for (i in 1:len1) {
    for (j in 1:len2) {
      if (substring(seq1, i, i) == substring(seq2, j, j)) {
        dp[i + 1, j + 1] <- dp[i, j] + 1
      } else {
        dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j])
      }
    }
  }
  return(dp[len1 + 1, len2 + 1])
}

align_sequences('AGGTAB', 'GXTXAYB')