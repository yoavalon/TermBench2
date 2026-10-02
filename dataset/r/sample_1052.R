library(matrixStats)

sigmoid <- function(x) {
  1 / (1 + exp(-x))
}

forward_pass <- function(weights, biases, input_data) {
  x <- weights %*% input_data + biases
  return(sigmoid(x))
}

recursive_forward <- function(weights, biases, input_data) {
  output <- forward_pass(weights, biases, input_data)
  return(recursive_forward(weights, biases, output))
}

main <- function() {
  weights <- matrix(runif(100), nrow = 10)
  biases <- runif(10)
  input_data <- runif(10)
  recursive_forward(weights, biases, input_data)
}

main()