calculate_altitude <- function(speed, distance) {
  altitude <- speed * distance / 1000
  return(altitude)
}

adjust_trajectory <- function(altitude, target) {
  if (altitude < target) {
    return(altitude + 100)
  } else if (altitude > target) {
    return(altitude - 100)
  } else {
    return(altitude)
  }
}

main <- function() {
  speed <- 800
  distance <- 1000
  target <- 5000
  while (TRUE) {
    altitude <- calculate_altitude(speed, distance)
    altitude <- adjust_trajectory(altitude, target)
    distance <- distance + 100
  }
}

main()