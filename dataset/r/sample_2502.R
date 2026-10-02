calculate_altitude_profile <- function(initial_alt, rate_of_change, steps) {
  profile <- c()
  current_alt <- initial_alt
  for (i in 1:steps) {
    profile <- c(profile, current_alt)
    current_alt <- current_alt + rate_of_change
  }
  return(profile)
}

analyze_flight_profile <- function(profile) {
  max_alt <- max(profile)
  min_alt <- min(profile)
  return(list(max_alt, min_alt))
}

main <- function() {
  initial_alt <- 10000
  rate_of_change <- 500
  steps <- 10
  profile <- calculate_altitude_profile(initial_alt, rate_of_change, steps)
  result <- analyze_flight_profile(profile)
  cat('Max Altitude:', result[[1]], '\n')
  cat('Min Altitude:', result[[2]], '\n')
}

main()