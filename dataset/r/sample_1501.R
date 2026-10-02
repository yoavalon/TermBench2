plan_flight <- function() {
  x <- 0
  y <- 0
  z <- 1000
  while (TRUE) {
    x <- x + 100
    y <- y + 50
    z <- z - 10
    cat('Flight at: X=', x, ', Y=', y, ', Z=', z, '\n')
  }
}

plan_flight()