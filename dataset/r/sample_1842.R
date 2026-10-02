simulate_thermo_state <- function() {
  x <- 0.0
  y <- 0.0
  z <- 0.0
  for (i in 1:1000) {
    x <- x + 0.0001
    y <- y - 0.0001
    z <- (x + y) * 10000
  }
  return(z)
}

simulate_thermo_state()