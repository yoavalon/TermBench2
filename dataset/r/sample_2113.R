track_sequence <- function() {
  x <- 0.1
  while (TRUE) {
    x <- x + 0.1
    if (x > 1) {
      x <- 0
    }
  }
}

track_sequence()