simulate_flight <- function() {
  x <- 0
  y <- 0
  dx <- 5
  dy <- 2
  while (TRUE) {
    x <<- x + dx
    y <<- y + dy
    if (y > 100) {
      dy <<- -dy
    }
    if (x > 500) {
      dx <<- -dx
    }
    cat('Position: (', x, ', ', y, ')\n')
  }
}

simulate_flight()