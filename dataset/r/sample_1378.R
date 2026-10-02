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

process_sequences <- function(sequences) {
  results <- list()
  for (i in 1:(length(sequences) - 1)) {
    for (j in (i + 1):length(sequences)) {
      results <- c(results, list(list(sequences[i], sequences[j], align_sequences(sequences[i], sequences[j]))))
    }
  }
  return(results)
}

main <- function() {
  sequences <- c('ATCG', 'AGCT', 'GCTA', 'CGTA')
  results <- process_sequences(sequences)
  for (result in results) {
    cat('Alignment between', result[[1]], 'and', result[[2]], ': Score =', result[[3]], '\n')
  }
}

main()