transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- a * x + b * y + c * z
    y <- a * y + b * z + c * x
    z <- a * z + b * x + c * y
  }
}

main <- transform_coordinates
main(1, 0, 0, 1, 1, 0)