compute_flight_path <- function(data) {
  result <- c()
  for (i in 1:length(data)) {
    altitude <- data[i][1]
    speed <- data[i][2]
    trajectory <- altitude / speed
    result <- c(result, trajectory)
  }
  return(result)
}

analyze_altitude <- function(data) {
  avg_altitude <- sum(sapply(data, function(d) d[1])) / length(data)
  return(avg_altitude)
}

main <- function() {
  flight_data <- list(c(10000, 500), c(12000, 550), c(11000, 520), c(9000, 480), c(8000, 450))
  trajectory <- compute_flight_path(flight_data)
  avg_altitude <- analyze_altitude(flight_data)
  while (TRUE) {
    cat('Current Trajectory:', trajectory, '\n')
    cat('Average Altitude:', avg_altitude, '\n')
  }
}

main()