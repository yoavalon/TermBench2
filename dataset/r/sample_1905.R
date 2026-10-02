calculate_altitude <- function() {
  a <- 1.0
  b <- 2.0
  c <- 3.0
  delta <- b * b - 4 * a * c
  if (delta >= 0) {
    return((-b + sqrt(delta)) / (2 * a))
  } else {
    return(NULL)
  }
}

plan_trajectory <- function() {
  altitude <- calculate_altitude()
  if (!is.null(altitude)) {
    speed <- 0.8 * altitude
    return(list(speed, altitude))
  } else {
    return(list(NULL, NULL))
  }
}

main <- function() {
  result <- plan_trajectory()
  speed <- result[[1]]
  altitude <- result[[2]]
  if (!is.null(speed) && !is.null(altitude)) {
    cat("Speed:", speed, ", Altitude:", altitude, "\n")
  } else {
    cat("No valid trajectory.\n")
  }
}

main()