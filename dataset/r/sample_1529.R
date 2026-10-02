flight_planner <- function() {
  a <- 1
  b <- 1
  c <- 0
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
    if (c > 30000) {
      a <- 1
      b <- 1
    }
  }
}

flight_planner()