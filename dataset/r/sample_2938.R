calculate_altitude <- function(time) {
  g <- 9.81
  v0 <- 500
  t <- time
  altitude <- v0 * t - 0.5 * g * t^2
  return(altitude)
}

calculate_distance <- function(time, speed) {
  distance <- speed * time
  return(distance)
}

trajectory_planning <- function() {
  while (TRUE) {
    t <- 0
    while (t < 3600) {
      a <- calculate_altitude(t)
      d <- calculate_distance(t, 900)
      if (a < 0) {
        break
      }
      cat('Time:', t, 'seconds, Altitude:', a, 'meters, Distance:', d, 'meters\n')
      t <- t + 10
    }
    cat('Cruise altitude reached. Adjusting speed for descent.\n')
    speed <- 500
    while (t < 7200) {
      a <- calculate_altitude(t)
      d <- calculate_distance(t, speed)
      if (a < 0) {
        break
      }
      cat('Time:', t, 'seconds, Altitude:', a, 'meters, Distance:', d, 'meters\n')
      t <- t + 10
    }
  }
}

main <- function() {
  trajectory_planning()
}

main()