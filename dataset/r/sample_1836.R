transform_coordinates <- function(x, y, z, a, b, c) {
  x1 <- x * a + y * b + z * c
  y1 <- x * b - y * a + z * c
  z1 <- x * c + y * c - z * a
  return(c(x1, y1, z1))
}

if (identical(commandArgs(trailingOnly = TRUE), character(0))) {
  transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5)
}