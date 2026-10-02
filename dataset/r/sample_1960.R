r
calculate_altitude <- function(speed, rate) {
  return(speed * rate)
}

adjust_altitude <- function(current, target) {
  difference <- target - current
  correction <- difference * 0.1
  return(current + correction)
}

main <- function() {
  initial_speed <- 500.5
  rate <- 0.8
  target_altitude <- 45000.0
  current_altitude <- 0.0
  for (i in 1:100) {
    current_altitude <- calculate_altitude(initial_speed, rate)
    current_altitude <- adjust_altitude(current_altitude, target_altitude)
    if (abs(current_altitude - target_altitude) < 100) {
      break
    }
  }
  print(current_altitude)
}

main()