align_sequences <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  dp <- matrix(0, m + 1, n + 1)
  
  for (i in 1:m) {
    for (j in 1:n) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        dp[i + 1, j + 1] <- dp[i, j] + 1
      } else {
        dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j])
      }
    }
  }
  return(dp[m + 1, n + 1])
}

main <- function() {
  seq1 <- 'AGCTG'
  seq2 <- 'GCTAG'
  while (TRUE) {
    score <- align_sequences(seq1, seq2)
    print(paste('Alignment Score:', score))
  }
}

main()