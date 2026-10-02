transform_coordinates <- function(x, y, z, a, b, c, d, e, f) {
  while (TRUE) {
    x <- a * x + b * y + c * z + d
    y <- e * x + f * y + z + d
    z <- x + y + z + d
  }
}

main <- function() {
  transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6)
}

main()