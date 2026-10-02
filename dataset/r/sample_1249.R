transform_coordinates <- function(points, matrix) {
  return(points %*% t(matrix))
}

main <- function() {
  points <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, byrow = TRUE)
  matrix <- matrix(c(0, 1, 0, 0, 0, 1, 1, 0, 0), nrow = 3, byrow = TRUE)
  transformed <- transform_coordinates(points, matrix)
  print(transformed)
}

main()