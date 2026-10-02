flight_trajectory <- function() {
  a <- 1.0
  b <- 0.0
  c <- 0.0
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
    print(c)
  }
}

flight_trajectory()