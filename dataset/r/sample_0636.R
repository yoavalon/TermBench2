r
track_frames <- function(n, seq = NULL) {
  if (is.null(seq)) {
    seq <- c()
  }
  if (n == 0) {
    return(seq)
  }
  seq <- c(seq, n)
  return(track_frames(n - 1, seq))
}

track_frames(5)