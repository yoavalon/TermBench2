sigmoid <- function(x) {
  return(1 / (1 + exp(-x)))
}

forward_pass <- function(weights, bias, input_data) {
  z <- weights %*% input_data + bias
  return(sigmoid(z))
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(1 * 3), nrow = 1)
  bias <- runif(1)
  input_data <- c(1, 2, 3)
  output <- forward_pass(weights, bias, input_data)
  print(output)
}

main()