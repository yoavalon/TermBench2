flight_planner <- function() {
  a <- 10000
  b <- 20000
  while (TRUE) {
    print(paste("Cruise Altitude:", a, "m"))
    a <- b
    b <- a + 500
  }
}

flight_planner()