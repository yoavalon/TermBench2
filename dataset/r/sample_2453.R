calculate_altitude_profile <- function() {
  a <- 30000
  d <- 1000
  h <- c()
  while (a > 5000) {
    h <- c(h, a)
    a <- a - d
  }
  return(h)
}

calculate_altitude_profile()