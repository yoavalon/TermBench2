generate_sequence <- function(length) {
  sample(c("A", "C", "G", "T"), length, replace = TRUE)
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
  while (TRUE) {
    seq1 <- paste(generate_sequence(100), collapse = "")
    seq2 <- paste(generate_sequence(100), collapse = "")
    alignment_score <- align_sequences(seq1, seq2)
    cat('Alignment Score:', alignment_score, '\n')
  }
}

main()