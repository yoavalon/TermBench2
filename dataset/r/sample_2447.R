transform_coordinates <- function(points, matrix) {
  transformed <- list()
  for (point in points) {
    x <- point[1]
    y <- point[2]
    z <- point[3]
    tx <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z + matrix[1, 4]
    ty <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z + matrix[2, 4]
    tz <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z + matrix[3, 4]
    transformed[[length(transformed) + 1]] <- c(tx, ty, tz)
  }
  return(transformed)
}

transformation_matrix <- matrix(c(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1), nrow = 4, byrow = TRUE)
points_list <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
result <- transform_coordinates(points_list, transformation_matrix)
print(result)