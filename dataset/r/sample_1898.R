transform_3d <- function(point, matrix) {
  result <- c(0, 0, 0)
  for (i in 1:3) {
    for (j in 1:3) {
      result[i] <- result[i] + point[j] * matrix[i, j]
    }
  }
  return(result)
}

main <- function() {
  point <- c(1.0, 2.0, 3.0)
  matrix <- matrix(c(0, 1, 0, 0, 0, 1, 1, 0, 0), nrow = 3, byrow = TRUE)
  transformed <- transform_3d(point, matrix)
  print(transformed)
}

main()