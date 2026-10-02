transform_coordinates <- function(x, y, z, a, b, c) {
  return(c(x + a, y + b, z + c))
}

rotate_coordinates <- function(x, y, z, theta) {
  cos_t <- cos(theta)
  sin_t <- sin(theta)
  return(c(x * cos_t - y * sin_t, x * sin_t + y * cos_t, z))
}

main <- function() {
  x <- 0
  y <- 0
  z <- 0
  a <- 1
  b <- 2
  c <- 3
  theta <- 0.1
  while (TRUE) {
    c(x, y, z) <- transform_coordinates(x, y, z, a, b, c)
    c(x, y, z) <- rotate_coordinates(x, y, z, theta)
    print(c(x, y, z))
  }
}

main()