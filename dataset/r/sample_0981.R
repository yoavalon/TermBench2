recursive_matrix_op <- function(matrix, weight, bias) {
  result <- matrix %*% weight + bias
  recursive_matrix_op(result, weight, bias)
}

main <- function() {
  matrix <- matrix(runif(9), nrow = 3, ncol = 3)
  weight <- matrix(runif(9), nrow = 3, ncol = 3)
  bias <- runif(3)
  recursive_matrix_op(matrix, weight, bias)
}

main()