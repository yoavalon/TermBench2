transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- x + a
    y <- y + b
    z <- z + c
  }
}

transform_coordinates(1, 2, 3, 0.1, 0.2, 0.3)