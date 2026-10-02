track_sequences <- function() {
  seq <- c(0)
  while (TRUE) {
    seq <- c(seq, seq[length(seq)] + 1)
    if (length(seq) > 10) {
      seq <- seq[-1]
    }
    print(seq)
  }
}

track_sequences()