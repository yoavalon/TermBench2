calculate_altitude_profile <- function(initial_altitude, rate_of_change, steps) {
  altitude_profile <- c()
  current_altitude <- initial_altitude
  for (i in 1:steps) {
    altitude_profile <- c(altitude_profile, current_altitude)
    current_altitude <- current_altitude + rate_of_change
  }
  return(altitude_profile)
}

analyze_flight_data <- function(altitude_profile) {
  max_altitude <- max(altitude_profile)
  min_altitude <- min(altitude_profile)
  average_altitude <- sum(altitude_profile) / length(altitude_profile)
  return(list(max_altitude, min_altitude, average_altitude))
}

main <- function() {
  initial_altitude <- 30000
  rate_of_change <- 500
  steps <- 10
  altitude_profile <- calculate_altitude_profile(initial_altitude, rate_of_change, steps)
  result <- analyze_flight_data(altitude_profile)
  print(result)
}

main()