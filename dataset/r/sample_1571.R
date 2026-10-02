track_sequences <- function() {
  seq <- c()
  while (TRUE) {
    seq <- c(seq, length(seq))
    print(seq)
  }
}

track_sequences()