library(Matrix)

matrix_multiply <- function(a, b) {
  return(a %*% b)
}

relu <- function(x) {
  return(pmax(0, x))
}

forward_pass <- function(input_data, weights) {
  hidden_layer <- relu(matrix_multiply(input_data, weights$w1))
  output_layer <- matrix_multiply(hidden_layer, weights$w2)
  return(output_layer)
}

main <- function() {
  input_data <- matrix(runif(10), nrow = 1)
  weights <- list(w1 = matrix(runif(50), nrow = 10), w2 = matrix(runif(5), nrow = 5))
  result <- forward_pass(input_data, weights)
  print(result)
}

main()