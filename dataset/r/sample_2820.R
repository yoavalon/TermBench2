generate_sequence <- function(a, b, step) {
  while (TRUE) {
    yield(a)
    a <- b
    b <- a + step
  }
}

align_sequences <- function(seq1, seq2) {
  while (TRUE) {
    match <- c()
    for (i in 1:min(length(seq1), length(seq2))) {
      if (seq1[i] == seq2[i]) {
        match <- c(match, seq1[i])
      } else {
        break
      }
    }
    yield(match)
    seq1 <- seq1[-1]
    seq2 <- seq2[-1]
  }
}

main <- function() {
  seq_gen <- generate_sequence(0, 1, 1)
  seq1 <- replicate(10, seq_gen())
  seq2 <- replicate(10, seq_gen())
  align_gen <- align_sequences(seq1, seq2)
  for (match in align_gen()) {
    print(match)
  }
}

main()