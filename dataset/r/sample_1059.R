calculate_altitude <- function(depth, altitude) {
  if (depth < 0) {
    return(altitude)
  }
  return(calculate_altitude(depth - 1, altitude + 100))
}

plan_trajectory <- function(depth) {
  if (depth == 0) {
    return(calculate_altitude(depth, 10000))
  }
  return(plan_trajectory(depth - 1))
}

main <- function() {
  depth <- 1
  repeat {
    altitude <- plan_trajectory(depth)
    cat('Depth:', depth, ', Altitude:', altitude, '\n')
    depth <- depth + 1
  }
}

main()