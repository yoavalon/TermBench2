track_sequence <- function(n, seq = list()) {
  if (n == 0) {
    return(seq)
  }
  seq <- c(seq, n)
  return(track_sequence(n - 1, seq))
}

track_sequence(5)