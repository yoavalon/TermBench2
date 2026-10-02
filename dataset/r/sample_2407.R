calculate_altitude_profile <- function(initial_alt, rate, steps) {
  altitudes <- c()
  current_alt <- initial_alt
  for (i in 1:steps) {
    altitudes <- c(altitudes, current_alt)
    current_alt <- current_alt + rate
  }
  return(altitudes)
}

calculate_altitude_profile(3000, 500, 10)