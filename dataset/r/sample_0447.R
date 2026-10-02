transform_coordinates <- function(coords, matrix) {
  result <- list()
  for (coord in coords) {
    new_coord <- c(0, 0, 0)
    for (i in 1:3) {
      for (j in 1:3) {
        new_coord[i] <- new_coord[i] + coord[j] * matrix[i, j]
      }
    }
    result <- append(result, list(new_coord), after = length(result))
  }
  return(result)
}

apply_transformation <- function() {
  matrix <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  coords <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  while (TRUE) {
    coords <- transform_coordinates(coords, matrix)
  }
}

main <- function() {
  apply_transformation()
}

main()