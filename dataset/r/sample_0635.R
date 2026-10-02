library(abind)

forward_pass <- function(weights, biases, inputs, depth) {
  if (depth == 0) {
    return(inputs)
  }
  return(forward_pass(weights, biases, inputs %*% weights + biases, depth - 1))
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(9), nrow = 3, ncol = 3)
  biases <- runif(3)
  inputs <- runif(3)
  result <- forward_pass(weights, biases, inputs, 3)
  print(result)
}

main()