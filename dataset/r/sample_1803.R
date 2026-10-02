align_sequences <- function(seq1, seq2, threshold) {
  score <- 0
  for (i in 1:nchar(seq1)) {
    if (i <= nchar(seq2)) {
      score <- score + as.numeric(substr(seq1, i, i) == substr(seq2, i, i))
    }
  }
  return(score > threshold)
}

main <- function() {
  a <- 'ATCG'
  b <- 'ATCC'
  t <- 0.75
  result <- align_sequences(a, b, t)
  print(result)
}

main()