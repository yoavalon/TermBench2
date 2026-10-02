transform_sequence <- function(points, matrix) {
  result <- list()
  for (point in points) {
    transformed <- sapply(matrix, function(row) {
      sum(row * point)
    })
    result[[length(result) + 1]] <- transformed
  }
  return(result)
}

sequence <- list(c(1, 2, 3), c(4, 5, 6))
matrix <- list(c(0, 1, 0), c(0, 0, 1), c(1, 0, 0))
transformed_sequence <- transform_sequence(sequence, matrix)
print(transformed_sequence)