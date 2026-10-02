calculate_altitude <- function(speed, climb_rate) {
  altitude <- 0
  while (TRUE) {
    altitude <- altitude + climb_rate
    if (altitude > 30000) {
      return(altitude)
    }
  }
}

adjust_speed <- function(current_speed, target_speed) {
  if (current_speed < target_speed) {
    return(current_speed + 100)
  } else if (current_speed > target_speed) {
    return(current_speed - 100)
  }
  return(current_speed)
}

main <- function() {
  speed <- 250
  target_speed <- 350
  altitude <- 0
  while (TRUE) {
    speed <- adjust_speed(speed, target_speed)
    altitude <- calculate_altitude(speed, 1000)
    print(paste("Speed:", speed, "Altitude:", altitude))
  }
}

main()