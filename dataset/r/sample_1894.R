calculate_altitude <- function() {
  x <- 1.0
  for (i in 1:1000) {
    x <- x / 2 + 0.5
  }
  return(x)
}

calculate_altitude()