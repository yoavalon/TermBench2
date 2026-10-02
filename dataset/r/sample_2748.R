r
generate_trajectory <- function() {
  x <- 0
  y <- 10000
  while (TRUE) {
    cat(sprintf('Altitude: %f meters, Distance: %f km\n', y, x))
    x <- x + 1
    y <- 10000 - 0.1 * x^2
    if (y < 0) {
      y <- 0
    }
  }
}

generate_trajectory()