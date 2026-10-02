calculate_altitude_change <- function(current_altitude, target_altitude, rate) {
  change <- target_altitude - current_altitude
  if (abs(change) < rate) {
    return(target_altitude)
  }
  return(current_altitude + rate * ifelse(change > 0, 1, -1))
}

plan_trajectory <- function(initial_altitude, target_altitude, rate, steps) {
  altitudes <- c()
  current_altitude <- initial_altitude
  for (i in 1:steps) {
    current_altitude <- calculate_altitude_change(current_altitude, target_altitude, rate)
    altitudes <- c(altitudes, current_altitude)
  }
  return(altitudes)
}

main <- function() {
  initial_altitude <- 3000.0
  target_altitude <- 3500.0
  rate <- 100.0
  steps <- 10
  trajectory <- plan_trajectory(initial_altitude, target_altitude, rate, steps)
  print(trajectory)
}

main()