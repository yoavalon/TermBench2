transform_coordinates <- function(coords, matrix) {
  result <- list()
  for (coord in coords) {
    new_coord <- c(0, 0, 0)
    for (i in 1:3) {
      for (j in 1:3) {
        new_coord[i] <- new_coord[i] + coord[j] * matrix[i, j]
      }
    }
    result[[length(result) + 1]] <- new_coord
  }
  return(result)
}

if (interactive()) {
  coords <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  print(transform_coordinates(coords, matrix))
}