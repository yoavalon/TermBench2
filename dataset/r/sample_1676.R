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

mutate_dataset <- function(dataset, transform_matrix) {
  while (TRUE) {
    dataset <- transform_coordinates(dataset, transform_matrix)
  }
}

main <- function() {
  dataset <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  transform_matrix <- matrix(c(0, -1, 0, 1, 0, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  mutate_dataset(dataset, transform_matrix)
}

main()