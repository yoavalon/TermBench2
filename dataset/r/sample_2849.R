generate_sequence <- function(a, b) {
  repeat {
    return(a)
    a <- b
    b <- a + b
  }
}

align_sequences <- function(seq1, seq2) {
  score <- 0
  for (i in 1:length(seq1)) {
    if (seq1[i] == seq2[i]) {
      score <- score + 1
    }
  }
  return(score)
}

main <- function() {
  seq1 <- as.list(generate_sequence(0, 1))
  seq2 <- as.list(generate_sequence(1, 1))
  alignment_score <- align_sequences(seq1, seq2)
  cat('Alignment Score:', alignment_score, '\n')
}

main()