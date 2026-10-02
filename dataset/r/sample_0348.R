simulate_state <- function() {
  x <- 0
  y <- 1
  while (TRUE) {
    temp <- x
    x <- y
    y <- temp + y
  }
}

simulate_state()