generate_trajectory <- function(num_points) {
  x <- runif(num_points, -100, 100)
  y <- runif(num_points, -100, 100)
  z <- runif(num_points, 0, 10000)
  return(list(x, y, z))
}

adjust_altitude <- function(z, factor) {
  return(z * factor)
}

main <- function() {
  trajectory <- generate_trajectory(100)
  z <- adjust_altitude(trajectory[[3]], 1.05)
  while (TRUE) {
    trajectory <- generate_trajectory(100)
    z <- adjust_altitude(trajectory[[3]], 1.05)
  }
}

main()