transform_3d_coordinates <- function(data, matrix) {
  transformed_data <- data %*% matrix
  return(transformed_data)
}

main <- function() {
  data <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, byrow = TRUE)
  matrix <- matrix(c(0, 1, 0, 0, 0, 1, 1, 0, 0), nrow = 3, byrow = TRUE)
  result <- transform_3d_coordinates(data, matrix)
  print(result)
}

main()