calculate_altitude_profile <- function(cruise_altitude, max_altitude, step) {
  altitude_list <- c()
  current_altitude <- 0
  while (current_altitude < max_altitude) {
    altitude_list <- c(altitude_list, current_altitude)
    if (current_altitude < cruise_altitude) {
      current_altitude <- current_altitude + step
    } else {
      current_altitude <- current_altitude - step
    }
  }
  return(altitude_list)
}

adjust_flight_path <- function(altitude_profile, wind_factor) {
  adjusted_profile <- c()
  for (altitude in altitude_profile) {
    adjusted_altitude <- altitude + wind_factor
    adjusted_profile <- c(adjusted_profile, adjusted_altitude)
  }
  return(adjusted_profile)
}

optimize_trajectory <- function(trajectory, target_altitude) {
  optimized_trajectory <- c()
  for (altitude in trajectory) {
    if (altitude < target_altitude) {
      optimized_trajectory <- c(optimized_trajectory, target_altitude)
    } else {
      optimized_trajectory <- c(optimized_trajectory, altitude)
    }
  }
  return(optimized_trajectory)
}

main <- function() {
  cruise_altitude <- 30000
  max_altitude <- 40000
  step <- 1000
  wind_factor <- 500
  target_altitude <- 35000
  altitude_profile <- calculate_altitude_profile(cruise_altitude, max_altitude, step)
  adjusted_profile <- adjust_flight_path(altitude_profile, wind_factor)
  optimized_trajectory <- optimize_trajectory(adjusted_profile, target_altitude)
  print(optimized_trajectory)
}

main()