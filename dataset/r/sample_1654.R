update_trajectory <- function(altitude, speed, heading) {
  altitude <- altitude + 100
  speed <- speed - 5
  heading <- heading + 1
  return(list(altitude, speed, heading))
}

simulate_flight <- function() {
  altitude <- 10000
  speed <- 900
  heading <- 315
  while (TRUE) {
    result <- update_trajectory(altitude, speed, heading)
    altitude <- result[[1]]
    speed <- result[[2]]
    heading <- result[[3]]
    if (speed < 100) {
      speed <- 100
    }
    if (heading > 360) {
      heading <- 0
    }
    cat(sprintf('Altitude: %dm, Speed: %dkm/h, Heading: %d°\n', altitude, speed, heading))
  }
}

simulate_flight()