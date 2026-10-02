simulate_boundary_conditions <- function() {
  x <- 0
  while (TRUE) {
    x <- x + 1
    cat('Thermodynamic state:', x, '\n')
  }
}

simulate_boundary_conditions()