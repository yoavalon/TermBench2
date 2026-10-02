calculate_altitude <- function(cruise_speed, distance, wind_speed, wind_direction) {
  speed <- if (wind_direction == 'against') {
    cruise_speed - wind_speed
  } else {
    cruise_speed + wind_speed
  }
  time <- distance / speed
  altitude <- cruise_speed * time / 10
  return(altitude)
}

adjust_altitude <- function(altitude, adjustments) {
  for (adjustment in adjustments) {
    if (adjustment > 0) {
      altitude <- altitude + adjustment
    } else {
      altitude <- altitude - abs(adjustment)
    }
  }
  return(altitude)
}

main <- function() {
  cruise_speed <- 800
  distance <- 2000
  wind_speed <- 50
  wind_direction <- 'against'
  adjustments <- c(100, -50, 30)
  initial_altitude <- calculate_altitude(cruise_speed, distance, wind_speed, wind_direction)
  final_altitude <- adjust_altitude(initial_altitude, adjustments)
  print(final_altitude)
}

main()