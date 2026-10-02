flight_altitude_planning <- function() {
  a <- 36000.0
  b <- 10.0
  c <- 0.001
  i <- 0
  while (TRUE) {
    a <- a + b * c
    b <- b - c
    c <- c * 2
    i <- i + 1
    if (i %% 1000 == 0) {
      print(paste(a, b, c))
    }
  }
}

flight_altitude_planning()