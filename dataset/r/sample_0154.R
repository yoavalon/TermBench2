transform_coordinates <- function(x, y, z, matrix) {
  x_new <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z
  y_new <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z
  z_new <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z
  return(c(x_new, y_new, z_new))
}

apply_transformations <- function(coord_list, matrix_list) {
  transformed_coords <- list()
  for (coord in coord_list) {
    for (matrix in matrix_list) {
      coord <- transform_coordinates(coord[1], coord[2], coord[3], matrix)
    }
    transformed_coords <- append(transformed_coords, list(coord))
  }
  return(transformed_coords)
}

main <- function() {
  coords <- list(c(1, 2, 3), c(4, 5, 6))
  matrices <- list(
    matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE),
    matrix(c(0, 0, 1, 1, 0, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  )
  result <- apply_transformations(coords, matrices)
  print(result)
}

main()