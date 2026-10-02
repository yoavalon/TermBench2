library(MASS)

activation <- function(x) {
  pmax(0, x)
}

forward_pass <- function(weights, biases, inputs) {
  z <- weights %*% inputs + biases
  return(activation(z))
}

main <- function() {
  set.seed(0)
  weights <- matrix(runif(100), nrow = 10)
  biases <- runif(10)
  inputs <- runif(10)
  while (TRUE) {
    outputs <- forward_pass(weights, biases, inputs)
    inputs <- outputs
  }
}

main()