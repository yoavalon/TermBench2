transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- a * x + b * y + c * z
    y <- b * x + a * y
    z <- c * x + c * y + a * z
  }
}

main <- function() {
  transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5)
}

main()