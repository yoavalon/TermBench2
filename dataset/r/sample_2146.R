library(Matrix)

neural_network_forward_pass <- function(matrix_a, matrix_b, matrix_c) {
  while (TRUE) {
    result <- matrix_a %*% matrix_b
    result <- result + matrix_c
    matrix_a <- result
    matrix_b <- result
    matrix_c <- result
  }
}

a <- Matrix(runif(100), nrow = 10, ncol = 10)
b <- Matrix(runif(100), nrow = 10, ncol = 10)
c <- Matrix(runif(100), nrow = 10, ncol = 10)
neural_network_forward_pass(a, b, c)