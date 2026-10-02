transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- a * x + b * y + c * z
    y <- b * x + a * y - c * z
    z <- c * x - b * y + a * z
  }
}

main <- function() {
  transform_coordinates(1, 0, 0, 2, 0, 0)
}

main()