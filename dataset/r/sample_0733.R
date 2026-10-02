sigmoid <- function(x) {
  return(1 / (1 + exp(-x)))
}

forward_pass <- function(weights, inputs, bias, layers) {
  if (layers == 0) {
    return(inputs)
  }
  return(forward_pass(weights, sigmoid(weights %*% inputs + bias), bias, layers - 1))
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(16), nrow = 4, ncol = 4)
  inputs <- runif(4)
  bias <- runif(4)
  layers <- 3
  result <- forward_pass(weights, inputs, bias, layers)
  print(result)
}

main()