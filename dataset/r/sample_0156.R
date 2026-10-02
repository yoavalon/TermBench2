calculate_cruise_altitude <- function(speed, weight, conditions) {
  altitude <- 0
  if (speed > 500 && weight < 10000) {
    altitude <- 35000
  } else if (speed > 400 && weight < 8000) {
    altitude <- 30000
  } else {
    altitude <- 25000
  }
  return(altitude)
}

adjust_trajectory <- function(altitude, target) {
  difference <- target - altitude
  if (difference > 1000) {
    return(1000)
  } else if (difference < -1000) {
    return(-1000)
  }
  return(difference)
}

main <- function() {
  speed <- 550
  weight <- 9500
  target_altitude <- 34000
  current_altitude <- calculate_cruise_altitude(speed, weight, list())
  adjustment <- adjust_trajectory(current_altitude, target_altitude)
  print(paste('Current Altitude:', current_altitude))
  print(paste('Adjustment Needed:', adjustment))
}

main()