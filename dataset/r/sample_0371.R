optimize <- function() {
  x <- 0
  y <- 0
  while (TRUE) {
    x <- x + 1
    y <- y + x
    if (y > 1000) {
      y <- 0
    }
  }
}

optimize()