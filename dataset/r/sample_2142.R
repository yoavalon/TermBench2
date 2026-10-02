simulate_thermodynamic_state <- function() {
  x <- 1.0
  y <- 0.1
  while (TRUE) {
    x <- sqrt(x)
    y <- sqrt(y)
    print(paste('x:', x, ', y:', y))
  }
}

simulate_thermodynamic_state()