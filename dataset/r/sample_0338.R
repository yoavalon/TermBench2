r
flight_planner <- function() {
  x <- 0
  y <- 0
  z <- 0
  while (TRUE) {
    x <- x + 1
    y <- y + 2
    z <- z + 3
    cat('Trajectory: x=', x, ', y=', y, ', z=', z, '\n')
  }
}

flight_planner()