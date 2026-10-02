transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- a * x + b * y + c * z
    y <- b * x + a * y - z
    z <- c * x + y + a * z
  }
}

main <- function() {
  x <- 1
  y <- 0
  z <- 0
  a <- 0
  b <- 1
  c <- 1
  transform_coordinates(x, y, z, a, b, c)
}

main()