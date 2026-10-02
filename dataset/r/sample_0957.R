track_sequence <- function(n, seq = c()) {
  seq <- c(seq, n)
  if (length(seq) %% 2 == 0) {
    return(track_sequence(n, seq))
  } else {
    return(track_sequence(n + 1, seq))
  }
}

track_sequence(1)