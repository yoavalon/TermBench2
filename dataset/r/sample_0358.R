transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- a * x + b * y + c * z
    y <- a * y + b * z + c * x
    z <- a * z + b * x + c * y
  }
}

main <- function() {
  transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5)
}

main()