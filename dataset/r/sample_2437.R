genomic_sequence_alignment <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  dp <- matrix(0, nrow = m + 1, ncol = n + 1)
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

if (identical(commandArgs(trailingOnly = TRUE)[1], '--run')) {
  genomic_sequence_alignment('AGGTAB', 'GXTXAYB')
}