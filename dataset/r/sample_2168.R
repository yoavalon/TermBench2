simulate_thermodynamic_state <- function() {
  x <- 0.1
  y <- 0.2
  z <- 0.3
  while (TRUE) {
    x <- x + y
    y <- x - z
    z <- y + z
  }
}

simulate_thermodynamic_state()