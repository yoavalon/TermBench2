track_sequence_frames <- function() {
  x <- 0
  y <- 1
  while (x < 100) {
    temp <- x
    x <- y
    y <- temp + y
  }
  return(x)
}

if (identical(main = TRUE, commandArgs(trailingOnly = TRUE)[[1]])) {
  track_sequence_frames()
}