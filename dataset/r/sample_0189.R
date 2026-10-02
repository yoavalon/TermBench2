align_sequences <- function(seq1, seq2, max_iter) {
  score <- 0
  i <- 1
  j <- 1
  while (i <= nchar(seq1) && j <= nchar(seq2) && max_iter > 0) {
    if (substr(seq1, i, i) == substr(seq2, j, j)) {
      score <- score + 1
    }
    i <- i + 1
    j <- j + 1
    max_iter <- max_iter - 1
  }
  return(score)
}

main <- function() {
  seq1 <- 'AGTACGCA'
  seq2 <- 'TGACGTCA'
  iterations <- 5
  result <- align_sequences(seq1, seq2, iterations)
  print(result)
}

main()