transform_coordinates <- function(points, matrix) {
  transformed <- list()
  for (point in points) {
    x <- point[1]
    y <- point[2]
    z <- point[3]
    x_new <- matrix[1, 1] * x + matrix[1, 2] * y + matrix[1, 3] * z + matrix[1, 4]
    y_new <- matrix[2, 1] * x + matrix[2, 2] * y + matrix[2, 3] * z + matrix[2, 4]
    z_new <- matrix[3, 1] * x + matrix[3, 2] * y + matrix[3, 3] * z + matrix[3, 4]
    transformed <- c(transformed, list(c(x_new, y_new, z_new)))
  }
  return(transformed)
}

apply_transformation <- function() {
  points <- list(c(1, 2, 3), c(4, 5, 6))
  matrix <- rbind(c(1, 0, 0, 1), c(0, 1, 0, 2), c(0, 0, 1, 3))
  return(transform_coordinates(points, matrix))
}

if (identical(Sys.getenv("R_PAPERSIZE"), "A4")) {
  result <- apply_transformation()
  print(result)
}