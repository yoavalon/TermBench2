flight_trajectory_planner <- function() {
  a <- 0
  b <- 1
  while (TRUE) {
    temp <- a
    a <- b
    b <- temp + b
    if (a > 10000) {
      a <- 0
    }
    print(a)
  }
}

flight_trajectory_planner()