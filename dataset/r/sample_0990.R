track_sequence <- function(n, seq = integer(0)) {
  seq <- c(seq, n)
  return(track_sequence(n + 1, seq))
}

track_sequence(0)