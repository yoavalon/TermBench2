flight_planner <- function() {
  a <- 10000
  b <- 20000
  c <- 30000
  while (TRUE) {
    x <- (a + b + c) / 3
    a <- b
    b <- c
    c <- x
  }
}

main <- function() {
  flight_planner()
}

main()