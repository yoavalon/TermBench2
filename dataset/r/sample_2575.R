generate_altitude_sequence <- function(start, end, step) {
  sequence <- c()
  current <- start
  while (current <= end) {
    sequence <- c(sequence, current)
    current <- current + step
  }
  return(sequence)
}

calculate_flight_duration <- function(altitudes, speed) {
  times <- altitudes / speed
  return(times)
}

main <- function() {
  start_altitude <- 10000
  end_altitude <- 40000
  step_size <- 5000
  cruise_speed <- 1000
  altitudes <- generate_altitude_sequence(start_altitude, end_altitude, step_size)
  durations <- calculate_flight_duration(altitudes, cruise_speed)
  for (i in 1:length(altitudes)) {
    cat('Altitude:', altitudes[i], 'm, Duration:', sprintf('%.2f', durations[i]), 's\n')
  }
}

main()