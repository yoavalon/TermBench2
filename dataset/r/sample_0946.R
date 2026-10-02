track_sequence <- function(n, seq) {
  seq <- c(seq, n)
  return(track_sequence(n + 1, seq))
}

track_sequence(1, c())