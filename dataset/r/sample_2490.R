library(Matrix)

forward_pass <- function(matrix, weights) {
  for (i in 1:nrow(matrix)) {
    matrix[i, ] <- matrix[i, ] %*% weights
  }
  return(matrix)
}

if (isTRUE(interactive())) {
  data <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, byrow = TRUE)
  w <- matrix(c(0.5, 0.5, 0.5, 0.5), nrow = 2, byrow = TRUE)
  result <- forward_pass(data, w)
  print(result)
}