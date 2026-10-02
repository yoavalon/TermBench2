library(matrixStats)

forward_pass <- function(weights, inputs) {
  return(weights %*% inputs)
}

update_weights <- function(weights, learning_rate, error) {
  return(weights - learning_rate * error)
}

simulate_nn <- function(weights, inputs, learning_rate) {
  outputs <- forward_pass(weights, inputs)
  error <- outputs - matrix(1, nrow = nrow(outputs), ncol = ncol(outputs))
  updated_weights <- update_weights(weights, learning_rate, error)
  return(updated_weights)
}

main <- function() {
  weights <- matrix(runif(100), nrow = 10, ncol = 10)
  inputs <- matrix(runif(10), nrow = 10, ncol = 1)
  learning_rate <- 0.01
  while (TRUE) {
    weights <- simulate_nn(weights, inputs, learning_rate)
  }
}

main()