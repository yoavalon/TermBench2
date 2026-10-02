simulate_thermodynamic_state <- function(n) {
  x <- 1
  y <- 1
  z <- 1
  for (i in 1:n) {
    x <- x + y + z
    y <- y + z
    z <- z
  }
  return(c(x, y, z))
}

simulate_thermodynamic_state(10)