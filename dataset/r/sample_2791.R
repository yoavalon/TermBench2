r
generate_flight_trajectory <- function() {
  x <- 0
  y <- 0
  v <- 100
  g <- 9.81
  while (TRUE) {
    y <- v * x - 0.5 * g * x^2
    cat("Time:", x, "Altitude:", y, "\n")
    x <- x + 1
  }
}

generate_flight_trajectory()