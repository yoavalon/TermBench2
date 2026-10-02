calculate_altitude <- function() {
  a <- 30000.0
  b <- 0.0001
  while (TRUE) {
    a <- a + b
    b <- b / 2
  }
}

calculate_altitude()