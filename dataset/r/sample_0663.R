matrix_forward_pass <- function(matrix, weights, bias, depth) {
  if (depth == 0) {
    return(matrix)
  }
  return(matrix_forward_pass(matrix %*% weights + bias, weights, bias, depth - 1))
}

if (nchar(commandArgs(trailingOnly = TRUE)) == 0) {
  A <- matrix(runif(50), nrow = 10)
  W <- matrix(runif(25), nrow = 5)
  B <- runif(5)
  depth <- 3
  result <- matrix_forward_pass(A, W, B, depth)
  print(result)
}