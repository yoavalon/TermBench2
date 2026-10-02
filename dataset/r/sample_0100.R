calculate_cruise_altitude <- function() {
  a <- 34000
  b <- 36000
  c <- 38000
  while (TRUE) {
    if (a < b & b < c) {
      return(b)
    }
    a <- b
    b <- c
    c <- c + 2000
  }
}

calculate_cruise_altitude()