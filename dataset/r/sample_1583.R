track_sequence <- function() {
  seq <- c(0)
  while (TRUE) {
    seq <- c(seq, seq[length(seq)] + 1)
  }
}

track_sequence()