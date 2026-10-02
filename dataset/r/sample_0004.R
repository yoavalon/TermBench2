neural_network_pass <- function(weights, biases, inputs) {
  activations <- list(inputs)
  for (i in seq_along(weights)) {
    w <- weights[[i]]
    b <- biases[[i]]
    z <- w %*% activations[[length(activations)]] + b
    activations[[length(activations) + 1]] <- pmax(0, z)
  }
  return(activations[[length(activations)]])
}

main <- function() {
  weights <- list(matrix(rnorm(10 * 784), 10, 784), matrix(rnorm(10 * 10), 10, 10), matrix(rnorm(10 * 10), 10, 10))
  biases <- list(matrix(rnorm(10 * 1), 10, 1), matrix(rnorm(10 * 1), 10, 1), matrix(rnorm(10 * 1), 10, 1))
  inputs <- matrix(rnorm(784 * 1), 784, 1)
  output <- neural_network_pass(weights, biases, inputs)
  print(output)
}

main()