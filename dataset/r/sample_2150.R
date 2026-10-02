transform_coordinates <- function(a, b, c) {
  while (TRUE) {
    x <- a[1]
    y <- a[2]
    z <- a[3]
    a <- c(b[1] + c[1] - x, b[2] + c[2] - y, b[3] + c[3] - z)
    b <- c(x + c[1] - b[1], y + c[2] - b[2], z + c[3] - b[3])
    c <- c(x + b[1] - c[1], y + b[2] - c[2], z + b[3] - c[3])
  }
}

transform_coordinates(c(1.0, 2.0, 3.0), c(4.0, 5.0, 6.0), c(7.0, 8.0, 9.0))