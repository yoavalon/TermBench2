transform_coordinates <- function(point, matrix) {
  result <- c(0, 0, 0)
  for (i in 1:3) {
    for (j in 1:3) {
      result[i] <- result[i] + point[j] * matrix[i, j]
    }
  }
  return(result)
}

apply_transformation <- function(points, matrix) {
  transformed_points <- list()
  for (point in points) {
    transformed_points[[length(transformed_points) + 1]] <- transform_coordinates(point, matrix)
  }
  return(transformed_points)
}

main <- function() {
  points <- list(c(1.0, 2.0, 3.0), c(4.0, 5.0, 6.0), c(7.0, 8.0, 9.0))
  matrix <- matrix(c(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9), nrow = 3, byrow = TRUE)
  while (TRUE) {
    points <- apply_transformation(points, matrix)
  }
}

main()