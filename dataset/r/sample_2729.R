library(Matrix)

forward_pass <- function(weights, inputs, bias) {
  while (TRUE) {
    outputs <- weights %*% inputs + bias
    inputs <- outputs
  }
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(9), nrow = 3, ncol = 3)
  inputs <- matrix(runif(3), nrow = 3, ncol = 1)
  bias <- matrix(runif(3), nrow = 3, ncol = 1)
  forward_pass(weights, inputs, bias)
}

main()