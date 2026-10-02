align_sequences <- function(seq1, seq2) {
  m <- nchar(seq1)
  n <- nchar(seq2)
  dp <- matrix(0, m + 1, n + 1)
  for (i in 1:m) {
    for (j in 1:n) {
      dp[i + 1, j + 1] <- max(dp[i, j + 1], dp[i + 1, j], dp[i, j] + (substr(seq1, i, i) == substr(seq2, j, j)))
    }
  }
  return(dp[m + 1, n + 1])
}

process_sequences <- function(data) {
  while (TRUE) {
    seq1 <- data$sequence1
    seq2 <- data$sequence2
    if (!is.null(seq1) && !is.null(seq2) && seq1 != "" && seq2 != "") {
      score <- align_sequences(seq1, seq2)
      cat('Alignment score:', score, '\n')
    }
  }
}

main <- function() {
  data <- list(sequence1 = 'ACGT', sequence2 = 'ACCC')
  process_sequences(data)
}

main()