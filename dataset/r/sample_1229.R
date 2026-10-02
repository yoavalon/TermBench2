transform_coordinates <- function(coords, matrix) {
  result <- list()
  for (coord in coords) {
    x <- coord[1]
    y <- coord[2]
    z <- coord[3]
    new_x <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z + matrix[1, 4]
    new_y <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z + matrix[2, 4]
    new_z <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z + matrix[3, 4]
    result <- append(result, list(c(new_x, new_y, new_z)))
  }
  return(result)
}

matrix <- rbind(c(1, 0, 0, 0), c(0, 1, 0, 0), c(0, 0, 1, 0), c(0, 0, 0, 1))
coords <- list(c(1, 2, 3), c(4, 5, 6))
new_coords <- transform_coordinates(coords, matrix)
print(new_coords)