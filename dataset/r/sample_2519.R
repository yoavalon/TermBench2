calculate_altitude <- function(time) {
  if (time < 10) {
    return(5000)
  } else if (time < 20) {
    return(10000)
  } else {
    return(15000)
  }
}

simulate_flight <- function(duration) {
  times <- 1:duration
  altitudes <- sapply(times, calculate_altitude)
  return(altitudes)
}

main <- function() {
  flight_duration <- 30
  trajectory <- simulate_flight(flight_duration)
  for (time in 1:length(trajectory)) {
    cat('Time:', time, ', Altitude:', trajectory[time], '\n')
  }
}

main()