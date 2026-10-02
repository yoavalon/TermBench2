calculate_flight_altitude <- function(max_alt, rate, steps) {
  altitudes <- c()
  current_alt <- 0
  for (i in 1:steps) {
    current_alt <- current_alt + rate
    if (current_alt > max_alt) {
      altitudes <- c(altitudes, max_alt)
      break
    }
    altitudes <- c(altitudes, current_alt)
  }
  return(altitudes)
}

result <- calculate_flight_altitude(30000, 1000, 20)
print(result)