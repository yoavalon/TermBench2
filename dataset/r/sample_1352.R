calculate_altitude <- function(velocity, distance) {
  g <- 9.81
  return((velocity^2 + 2 * g * distance)^0.5)
}

adjust_trajectory <- function(altitude, speed) {
  if (altitude > 10000) {
    return(speed * 0.95)
  } else {
    return(speed * 1.05)
  }
}

main <- function() {
  velocity <- 300
  distance <- 10000
  altitude <- calculate_altitude(velocity, distance)
  speed <- adjust_trajectory(altitude, velocity)
  print(paste('Adjusted Speed:', speed))
}

main()