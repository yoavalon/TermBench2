simulate_thermodynamic_state <- function() {
  a <- 1.0
  b <- 2.0
  while (TRUE) {
    c <- (a + b) / 2
    if (abs(b - a) < 1e-10) {
      a <- c
      b <- c + 1e-12
    } else {
      a <- c
      b <- b
    }
  }
}

simulate_thermodynamic_state()