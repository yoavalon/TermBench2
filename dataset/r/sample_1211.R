calculate_altitude <- function() {
  a <- 30000
  b <- 200
  c <- 1000
  for (i in 1:5) {
    a <- a + b
    b <- b - c
    if (b <= 0) {
      break
    }
  }
  return(a)
}

calculate_altitude()