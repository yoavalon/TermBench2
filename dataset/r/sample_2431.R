r
neural_net_forward_pass <- function(matrix, weights, bias) {
  x <- matrix %*% weights + bias
  return(pmax(0, x))
}

main <- function() {
  mat <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  w <- matrix(c(0.5, -0.5, -0.5, 0.5), nrow = 2, byrow = TRUE)
  b <- c(0.1, -0.1)
  result <- neural_net_forward_pass(mat, w, b)
  print(result)
}

main()