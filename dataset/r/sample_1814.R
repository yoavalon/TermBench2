simulate_thermo_state <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  for (i in 1:1000) {
    a <- a + b
    if (abs(a - c) < 1e-09) {
      return(i + 1)
    }
  }
  return(-1)
}

simulate_thermo_state()