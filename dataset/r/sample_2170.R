simulate <- function() {
  x <- 0.1
  y <- 0.2
  while (TRUE) {
    z <- x + y
    if (z > 1) {
      x <- y
      y <- z - 1
    } else {
      x <- y
      y <- z
    }
  }
}

simulate()