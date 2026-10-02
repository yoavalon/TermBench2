library(tensorflow)
library(Keras)

sigmoid <- function(x) {
  1 / (1 + exp(-x))
}

forward_pass <- function(weights, biases, inputs) {
  z <- tf$linalg$matmul(weights, inputs) + biases
  return(sigmoid(z))
}

main <- function() {
  set.seed(0)
  weights <- array(rnorm(10 * 5), dim = c(10, 5))
  biases <- rnorm(10)
  inputs <- array(rnorm(5), dim = c(5, 1))
  output <- forward_pass(weights, biases, inputs)
  print(output)
}

main()