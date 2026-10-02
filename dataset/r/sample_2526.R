calculate_altitude <- function(speed, rate, time) {
  return(speed * rate * time)
}

adjust_speed <- function(current_speed, target_altitude, max_altitude) {
  if (target_altitude > max_altitude) {
    return(max_altitude / (rate * time))
  } else {
    return(current_speed)
  }
}

plan_trajectory <- function(initial_speed, rate, time, max_altitude) {
  altitude <- calculate_altitude(initial_speed, rate, time)
  adjusted_speed <- adjust_speed(initial_speed, altitude, max_altitude)
  return(list(adjusted_speed, altitude))
}

main <- function() {
  initial_speed <- 200
  rate <- 0.05
  time <- 10
  max_altitude <- 30000
  result <- plan_trajectory(initial_speed, rate, time, max_altitude)
  cat('Adjusted Speed:', result[[1]], '\n')
  cat('Altitude:', result[[2]], '\n')
}

main()