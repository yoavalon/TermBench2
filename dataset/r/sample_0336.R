simulate_state <- function() {
  x <- 1
  y <- 1
  while (TRUE) {
    x <- x + y
    y <- x - y
    if (x == 0) {
      x <- 1
      y <- 1
    }
  }
}

simulate_state()