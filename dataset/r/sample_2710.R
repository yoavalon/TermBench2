simulate <- function() {
  x <- 1.0
  y <- 0.0
  z <- 0.0
  repeat {
    x_new <- y
    y_new <- z
    z_new <- 3.9 * x * (1 - x) + z
    x <- x_new
    y <- y_new
    z <- z_new
    print(c(x, y, z))
  }
}

simulate()