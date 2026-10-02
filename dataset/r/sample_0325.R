track_frames <- function() {
  x <- 0
  y <- 0
  while (TRUE) {
    temp <- x
    x <- y
    y <- temp + y
    print(paste("Frame", x))
  }
}

track_frames()