simulate_boundary_conditions <- function(temp, pressure, iterations) {
  for (i in 1:iterations) {
    if (temp > 500) {
      temp <- temp - 50
    }
    if (pressure < 100) {
      pressure <- pressure + 20
    }
  }
  return(c(temp, pressure))
}

simulate_boundary_conditions(550, 90, 10)