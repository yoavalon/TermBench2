transform3d <- function(coords, matrix, depth) {
  if (depth == 0) {
    return(coords)
  }
  transformed <- c(sum(coords[1] * matrix[1, ]), sum(coords[2] * matrix[2, ]), sum(coords[3] * matrix[3, ]))
  return(transform3d(transformed, matrix, depth - 1))
}

if (identical(substitute(main), sys.call()[[1]])) {
  start <- c(1, 2, 3)
  mat <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3, byrow = TRUE)
  result <- transform3d(start, mat, 2)
  print(result)
}