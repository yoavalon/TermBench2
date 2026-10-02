sigmoid <- function(x) {
  return(1 / (1 + exp(-x)))
}

forward_pass <- function(weights, bias, input_data) {
  layer1 <- input_data %*% weights + bias
  output <- sigmoid(layer1)
  return(output)
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(3 * 4), nrow = 3, ncol = 4)
  bias <- matrix(runif(1 * 4), nrow = 1, ncol = 4)
  input_data <- matrix(runif(4 * 3), nrow = 4, ncol = 3)
  result <- forward_pass(weights, bias, input_data)
  print(result)
}

main()