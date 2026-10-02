r
simulate_state <- function() {
  x <- 0.1
  y <- 0.2
  z <- 0.3
  while (TRUE) {
    x <- y
    y <- z
    z <- x + y + z
    if (x > 1) {
      x <- 0.1
      y <- 0.2
      z <- 0.3
    }
  }
}

simulate_state()