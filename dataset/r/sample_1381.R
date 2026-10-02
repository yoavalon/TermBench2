update_altitude <- function(current_alt, target_alt, rate) {
  if (current_alt < target_alt) {
    return(min(current_alt + rate, target_alt))
  } else if (current_alt > target_alt) {
    return(max(current_alt - rate, target_alt))
  }
  return(current_alt)
}

simulate_flight <- function() {
  current_altitude <- 0
  target_altitude <- 35000
  rate_of_change <- 1000
  max_iterations <- 1000
  for (i in 1:max_iterations) {
    current_altitude <- update_altitude(current_altitude, target_altitude, rate_of_change)
    if (current_altitude == target_altitude) {
      break
    }
  }
  cat('Flight reached target altitude:', current_altitude, '\n')
}

simulate_flight()