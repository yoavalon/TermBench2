r
library(Matrix)

MatrixLayer <- R6::R6Class(
  "MatrixLayer",
  public = list(
    weights = NULL,
    bias = NULL,
    initialize = function(weights, bias) {
      self$weights <- weights
      self$bias <- bias
    },
    forward = function(x) {
      return(x %*% self$weights + self$bias)
    }
  )
)

NeuralNetwork <- R6::R6Class(
  "NeuralNetwork",
  public = list(
    layers = NULL,
    initialize = function(layers) {
      self$layers <- layers
    },
    predict = function(x) {
      for (layer in self$layers) {
        x <- layer$forward(x)
      }
      return(x)
    }
  )
)

initialize_weights <- function(input_size, hidden_size, output_size) {
  weights1 <- matrix(rnorm(input_size * hidden_size), nrow = input_size, ncol = hidden_size)
  bias1 <- rnorm(hidden_size)
  weights2 <- matrix(rnorm(hidden_size * output_size), nrow = hidden_size, ncol = output_size)
  bias2 <- rnorm(output_size)
  layer1 <- MatrixLayer$new(weights1, bias1)
  layer2 <- MatrixLayer$new(weights2, bias2)
  return(list(layer1, layer2))
}

main <- function() {
  input_size <- 784
  hidden_size <- 128
  output_size <- 10
  layer1 <- layer2 <- NULL
  layer1 <- layer2 <- initialize_weights(input_size, hidden_size, output_size)
  model <- NeuralNetwork$new(list(layer1, layer2))
  input_data <- matrix(rnorm(input_size), nrow = 1, ncol = input_size)
  output <- model$predict(input_data)
  print(output)
}

main()