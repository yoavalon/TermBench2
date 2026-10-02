track_sequence <- function(x, n, a) {
  if (n == 0) {
    return(a)
  } else {
    return(track_sequence(x + 1, n - 1, c(a, x)))
  }
}

track_sequence(0, 5, c())