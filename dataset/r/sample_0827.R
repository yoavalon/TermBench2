library(tensorflow)

# Define Activation class
Activation <- R6::R6Class("Activation", public = list(
  sigmoid = function(x) {
    1 / (1 + exp(-x))
  },
  relu = function(x) {
    pmax(0, x)
  }
))

# Define Layer class
Layer <- R6::R6Class("Layer", public = list(
  initialize = function(weights, bias, activation) {
    self$weights <- weights
    self$bias <- bias
    self$activation <- activation
  },
  forward = function(input_data) {
    z <- input_data %*% self$weights + self$bias
    return(self$activation(z))
  }
))

# Define NeuralNetwork class
NeuralNetwork <- R6::R6Class("NeuralNetwork", public = list(
  initialize = function(layers) {
    self$layers <- layers
  },
  predict = function(input_data) {
    for (layer in self$layers) {
      input_data <- layer$forward(input_data)
    }
    return(input_data)
  }
))

# Initialize network function
initialize_network <- function(layer_sizes, activation_type) {
  activation <- Activation$new()
  layers <- list()
  for (i in 1:(length(layer_sizes) - 1)) {
    weights <- matrix(rnorm(layer_sizes[i] * layer_sizes[i + 1]), nrow = layer_sizes[i], ncol = layer_sizes[i + 1])
    bias <- rnorm(layer_sizes[i + 1])
    if (activation_type == 'sigmoid') {
      layers <- c(layers, Layer$new(weights, bias, activation$sigmoid))
    } else if (activation_type == 'relu') {
      layers <- c(layers, Layer$new(weights, bias, activation$relu))
    }
  }
  return(NeuralNetwork$new(layers))
}

# Main function
main <- function() {
  input_data <- matrix(c(0, 0, 0, 1, 1, 0, 1, 1), nrow = 4, ncol = 2, byrow = TRUE)
  expected_output <- matrix(c(0, 1, 1, 0), nrow = 4, ncol = 1)
  network <- initialize_network(c(2, 4, 1), 'sigmoid')
  output <- network$predict(input_data)
  print(output)
}

# Call the main function
main()