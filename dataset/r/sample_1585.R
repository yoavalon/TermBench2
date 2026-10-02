flight_planner <- function() {
  a <- 10000
  b <- 5000
  c <- 2500
  d <- 1250
  e <- 625
  while (TRUE) {
    a <- b
    b <- c
    c <- d
    d <- e
    e <- (a + b + c + d + e) / 5
    print(c(a, b, c, d, e))
  }
}

flight_planner()