simulate_thermodynamic_states <- function() {
  x <- 1
  y <- 1
  z <- 1
  while (TRUE) {
    x <- x + y
    y <- y + z
    z <- z + x
    print(c(x, y, z))
  }
}

simulate_thermodynamic_states()