transform_point <- function(x, y, z, matrix) {
  return(c(x * matrix[1, 1] + y * matrix[1, 2] + z * matrix[1, 3], 
            x * matrix[2, 1] + y * matrix[2, 2] + z * matrix[2, 3], 
            x * matrix[3, 1] + y * matrix[3, 2] + z * matrix[3, 3]))
}

apply_sequence_transformations <- function(points, sequence) {
  result <- points
  for (matrix in sequence) {
    new_points <- lapply(result, function(point) {
      transform_point(point[1], point[2], point[3], matrix)
    })
    result <- new_points
  }
  return(result)
}

main <- function() {
  points <- list(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1))
  sequence <- list(
    rbind(c(1, 0, 0), c(0, 1, 0), c(0, 0, 1)),
    rbind(c(0, -1, 0), c(1, 0, 0), c(0, 0, 1)),
    rbind(c(1, 0, 0), c(0, 1, 0), c(0, 0, -1))
  )
  transformed_points <- apply_sequence_transformations(points, sequence)
  for (point in transformed_points) {
    print(point)
  }
}

main()