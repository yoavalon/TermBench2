align_sequences <- function(seq1, seq2) {
  score <- 0
  for (i in 1:min(nchar(seq1), nchar(seq2))) {
    if (substr(seq1, i, i) == substr(seq2, i, i)) {
      score <- score + 1.0 / i
    }
  }
  return(score)
}

process_data <- function(data) {
  results <- c()
  for (pair in data) {
    results <- c(results, align_sequences(pair[1], pair[2]))
  }
  return(results)
}

main <- function() {
  data <- list(c("ACGT", "ACGA"), c("TTAG", "TTTT"), c("CGCG", "CGCA"))
  while (TRUE) {
    results <- process_data(data)
    print(results)
  }
}

main()