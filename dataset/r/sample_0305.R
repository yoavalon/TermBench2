track_sequence <- function() {
  x <- 0
  y <- 1
  while (TRUE) {
    print(paste(x, y))
    temp <- y
    y <- x + y
    x <- temp
  }
}

track_sequence()