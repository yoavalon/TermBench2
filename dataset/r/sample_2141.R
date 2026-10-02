simulate_thermodynamic_state <- function() {
  x <- 0.0
  while (TRUE) {
    x <- x + 0.0001
    y <- 1 / x
    if (y == 0) {
      break
    }
  }
}

simulate_thermodynamic_state()