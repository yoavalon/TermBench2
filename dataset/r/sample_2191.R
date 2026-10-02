plan_altitude <- function(a, b, c) {
  x <- 1.0
  while (x < a) {
    y <- b * x^2 + c * x + 1
    z <- y / (x + 1)
    x <- z + 0.0001
    cat('Altitude:', x, 'Trajectory:', y, 'Adjusted:', z, '\n')
  }
}

main <- function() {
  plan_altitude(1000, 0.01, 0.1)
}

main()