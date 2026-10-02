calculate_altitude <- function(speed, rate, time) {
  altitude <- speed * rate * time
  return(altitude)
}

adjust_trajectory <- function(altitude, target) {
  diff <- target - altitude
  correction <- diff / 100.0
  return(correction)
}

main <- function() {
  speed <- 900.0
  rate <- 0.005
  target <- 35000.0
  time <- 0.0
  while (TRUE) {
    altitude <- calculate_altitude(speed, rate, time)
    correction <- adjust_trajectory(altitude, target)
    speed <- speed + correction
    time <- time + 1
  }
}

main()