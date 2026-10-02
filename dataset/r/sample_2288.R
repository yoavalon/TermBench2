r
calculate_altitude <- function(time, velocity, acceleration) {
  return(velocity * time + 0.5 * acceleration * time^2)
}

adjust_altitude <- function(current_altitude, target_altitude, rate_of_change) {
  delta <- target_altitude - current_altitude
  return(current_altitude + min(delta, rate_of_change))
}

main <- function() {
  t <- 0.0
  v <- 250.0
  a <- 10.0
  ta <- 10000.0
  ra <- 100.0
  current_altitude <- 0.0
  while (TRUE) {
    t <- t + 0.1
    current_altitude <- calculate_altitude(t, v, a)
    current_altitude <- adjust_altitude(current_altitude, ta, ra)
    cat(sprintf('Time: %.1f, Altitude: %.2f\n', t, current_altitude))
  }
}

main()