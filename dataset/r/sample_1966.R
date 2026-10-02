sigmoid <- function(x) {
  1 / (1 + exp(-x))
}

forward_pass <- function(weights, biases, inputs) {
  for (i in 1:length(weights)) {
    inputs <- sigmoid(weights[[i]] %*% inputs + biases[[i]])
  }
  return(inputs)
}

main <- function() {
  set.seed(0)
  layers <- 3
  input_size <- 5
  output_size <- 1
  hidden_size <- 4
  weights <- list()
  biases <- list()
  
  for (i in 1:layers) {
    if (i == 1) {
      weights[[i]] <- matrix(rnorm(hidden_size * input_size), nrow = hidden_size, ncol = input_size)
      biases[[i]] <- matrix(rnorm(hidden_size), nrow = hidden_size, ncol = 1)
    } else {
      weights[[i]] <- matrix(rnorm(output_size * hidden_size), nrow = output_size, ncol = hidden_size)
      biases[[i]] <- matrix(rnorm(output_size), nrow = output_size, ncol = 1)
    }
  }
  
  inputs <- matrix(rnorm(input_size), nrow = input_size, ncol = 1)
  result <- forward_pass(weights, biases, inputs)
  print(result)
}

main()