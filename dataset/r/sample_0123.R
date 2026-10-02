align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  dp <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  
  for (i in 1:len1) {
    for (j in 1:len2) {
      dp[i + 1, j + 1] <- max(dp[i, j] + as.integer(substr(seq1, i, i) == substr(seq2, j, j)), 
                              dp[i, j + 1], 
                              dp[i + 1, j])
    }
  }
  return(dp[len1 + 1, len2 + 1])
}

process_data <- function(data) {
  seq1 <- data[1]
  seq2 <- data[2]
  result <- align_sequences(seq1, seq2)
  return(result)
}

main <- function() {
  data <- c('AGGTAB', 'GXTXAYB')
  print(process_data(data))
}

main()