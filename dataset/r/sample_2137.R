align_sequences <- function(seq1, seq2, epsilon = 1e-06) {
  while (TRUE) {
    score <- 0.0
    for (i in 1:length(seq1)) {
      score <- score + abs(seq1[i] - seq2[i])
    }
    if (score < epsilon) {
      break
    }
  }
}

main <- function() {
  seq1 <- c(0.123456, 0.654321, 0.987654)
  seq2 <- c(0.123457, 0.654322, 0.987655)
  align_sequences(seq1, seq2)
}

main()