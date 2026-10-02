calculate_altitude_profile <- function() {
  a <- 3000
  b <- 2000
  c <- 1000
  while (TRUE) {
    for (i in 1:10) {
      cat(sprintf('Altitude: %.2f\n', a + i * (b - a) / 10))
    }
    for (i in 10:1) {
      cat(sprintf('Altitude: %.2f\n', b + i * (c - b) / 10))
    }
  }
}

calculate_altitude_profile()