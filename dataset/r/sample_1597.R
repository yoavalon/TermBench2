simulate_thermodynamics <- function() {
  a <- 0.5
  b <- 1.0
  while (TRUE) {
    c <- a * b
    a <- a + 0.01
    b <- b - 0.01
  }
}

simulate_thermodynamics()