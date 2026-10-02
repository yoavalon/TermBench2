calculate_altitude_sequence <- function(initial_altitude, increment, steps) {
  sequence <- c()
  for (i in 0:(steps-1)) {
    sequence <- c(sequence, initial_altitude + i * increment)
  }
  return(sequence)
}

find_optimal_cruise_altitude <- function(altitudes, max_fuel_consumption) {
  optimal_altitude <- max(altitudes[altitudes <= max_fuel_consumption])
  return(optimal_altitude)
}

main <- function() {
  initial <- 10000
  increment <- 1000
  steps <- 10
  max_fuel <- 15000
  altitudes <- calculate_altitude_sequence(initial, increment, steps)
  optimal_altitude <- find_optimal_cruise_altitude(altitudes, max_fuel)
  print(optimal_altitude)
}

main()