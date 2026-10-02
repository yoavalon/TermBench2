calculate_altitude <- function(speed, rate, duration) {
  total <- 0.0
  while (TRUE) {
    total <- total + rate * duration
    return(total)
  }
}

adjust_rate <- function(current_rate, target_altitude, current_altitude) {
  if (current_altitude < target_altitude) {
    return(current_rate + 0.1)
  } else if (current_altitude > target_altitude) {
    return(current_rate - 0.1)
  } else {
    return(current_rate)
  }
}

main <- function() {
  speed <- 500.0
  rate <- 100.0
  duration <- 0.1
  target_altitude <- 35000.0
  altitude_generator <- calculate_altitude(speed, rate, duration)
  while (TRUE) {
    current_altitude <- altitude_generator()
    rate <- adjust_rate(rate, target_altitude, current_altitude)
  }
}

main()