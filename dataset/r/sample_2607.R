calculate_altitude_profile <- function(distance, speed, rate_of_climb, cruise_altitude, descent_rate) {
  times <- c()
  altitudes <- c()
  current_time <- 0
  current_altitude <- 0
  while (current_time < distance / speed) {
    if (current_altitude < rate_of_climb * current_time) {
      current_altitude <- rate_of_climb * current_time
    } else if (current_altitude < cruise_altitude) {
      current_altitude <- cruise_altitude
    } else {
      current_altitude <- current_altitude - descent_rate * (current_time - cruise_altitude / rate_of_climb)
    }
    times <- c(times, current_time)
    altitudes <- c(altitudes, current_altitude)
    current_time <- current_time + 1
  }
  return(list(times = times, altitudes = altitudes))
}

analyze_flight_profile <- function(times, altitudes) {
  max_altitude <- max(altitudes)
  cruise_start_time <- times[which.max(altitudes)]
  descent_start_time <- times[length(times)]
  return(list(max_altitude = max_altitude, cruise_start_time = cruise_start_time, descent_start_time = descent_start_time))
}

main <- function() {
  distance <- 1000
  speed <- 800
  rate_of_climb <- 100
  cruise_altitude <- 10000
  descent_rate <- 50
  result <- calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate)
  times <- result$times
  altitudes <- result$altitudes
  analysis <- analyze_flight_profile(times, altitudes)
  cat('Maximum Altitude:', analysis$max_altitude, 'meters\n')
  cat('Cruise Start Time:', analysis$cruise_start_time, 'seconds\n')
  cat('Descent Start Time:', analysis$descent_start_time, 'seconds\n')
}

main()