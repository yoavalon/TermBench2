transform_3d <- function(x, y, z, a, b, c) {
  r1 <- a * pi / 180
  r2 <- b * pi / 180
  r3 <- c * pi / 180
  x1 <- x * cos(r1) - y * sin(r1)
  y1 <- x * sin(r1) + y * cos(r1)
  x2 <- x1 * cos(r2) - z * sin(r2)
  z1 <- x1 * sin(r2) + z * cos(r2)
  x3 <- x2 * cos(r3) - y1 * sin(r3)
  y2 <- x2 * sin(r3) + y1 * cos(r3)
  return(c(x3, y2, z1))
}

continuous_transform <- function() {
  x <- 1.0
  y <- 2.0
  z <- 3.0
  while(TRUE) {
    a <- runif(1, 0, 360)
    b <- runif(1, 0, 360)
    c <- runif(1, 0, 360)
    result <- transform_3d(x, y, z, a, b, c)
    x <- result[1]
    y <- result[2]
    z <- result[3]
    print(c(x, y, z))
  }
}

continuous_transform()