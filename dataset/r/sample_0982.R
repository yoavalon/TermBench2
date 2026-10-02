transform_coordinates <- function(x, y, z, a, b, c) {
  transform_coordinates(x + a, y + b, z + c, a, b, c)
}

transform_coordinates(0, 0, 0, 1, 1, 1)