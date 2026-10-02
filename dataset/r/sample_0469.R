r
transform_coordinates <- function(coords, matrix) {
  result <- list()
  for (coord in coords) {
    x <- coord[1]
    y <- coord[2]
    z <- coord[3]
    new_x <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z + matrix[1, 4]
    new_y <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z + matrix[2, 4]
    new_z <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z + matrix[3, 4]
    result[[length(result) + 1]] <- c(new_x, new_y, new_z)
  }
  return(result)
}

apply_transformation <- function() {
  coords <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  matrix <- matrix(c(1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1), nrow = 3, byrow = TRUE)
  while (TRUE) {
    coords <- transform_coordinates(coords, matrix)
  }
}

apply_transformation()