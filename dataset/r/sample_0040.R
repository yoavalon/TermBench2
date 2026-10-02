simulate_thermodynamic_state <- function() {
  x <- 0
  y <- 0
  z <- 0
  while (x < 10) {
    x <- x + 1
    y <- y + x
    z <- z + y
  }
  return(z)
}

simulate_thermodynamic_state()