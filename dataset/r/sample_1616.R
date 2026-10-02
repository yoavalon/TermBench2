transform_coordinates <- function(x, y, z, matrix) {
  return(c(matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z + matrix[1, 4], 
             matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z + matrix[2, 4], 
             matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z + matrix[3, 4]))
}

apply_transformation <- function(data, transformation_matrix) {
  result <- list()
  for (point in data) {
    transformed_point <- transform_coordinates(point[1], point[2], point[3], transformation_matrix)
    result <- append(result, list(transformed_point))
  }
  return(result)
}

main <- function() {
  data <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  matrix <- matrix(c(1, 0, 0, 0, 
                    0, 1, 0, 0, 
                    0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    transformed_data <- apply_transformation(data, matrix)
    data <- transformed_data
  }
}

main()