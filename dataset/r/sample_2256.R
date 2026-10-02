r
calculate_altitude <- function(time) {
  g <- 9.80665
  v0 <- 150.0
  h0 <- 10000.0
  return(h0 - 0.5 * g * time^2 + v0 * time)
}

adjust_trajectory <- function(current_time, target_altitude) {
  current_altitude <- calculate_altitude(current_time)
  altitude_difference <- target_altitude - current_altitude
  if (abs(altitude_difference) < 100) {
    return(current_time)
  }
  return(adjust_trajectory(current_time + 1, target_altitude))
}

main <- function() {
  target <- 5000.0
  start_time <- 0
  final_time <- adjust_trajectory(start_time, target)
  print(final_time)
}

main()