library(Matrix)

MatrixOp <- R6::R6Class("MatrixOp", list(
  data = NULL,
  initialize = function(data) {
    self$data <- as.matrix(data)
  },
  multiply = function(other) {
    return(MatrixOp$new(self$data %*% other$data))
  },
  add = function(other) {
    return(MatrixOp$new(self$data + other$data))
  },
  sigmoid = function() {
    return(MatrixOp$new(1 / (1 + exp(-self$data))))
  },
  relu = function() {
    return(MatrixOp$new(pmax(0, self$data)))
  }
))

NeuralNetwork <- R6::R6Class("NeuralNetwork", list(
  layers = NULL,
  initialize = function(layers) {
    self$layers <- layers
  },
  forward_pass = function(input_data) {
    result <- input_data
    for (layer in self$layers) {
      result <- layer$forward(result)
    }
    return(result)
  }
))

Layer <- R6::R6Class("Layer", list(
  weights = NULL,
  activation = NULL,
  initialize = function(weights, activation) {
    self$weights <- MatrixOp$new(weights)
    self$activation <- activation
  },
  forward = function(input_data) {
    weighted_input <- self$weights$multiply(input_data)
    activated_output <- self$activation(weighted_input)
    return(activated_output)
  }
))

main <- function() {
  set.seed(0)
  input_data <- MatrixOp$new(matrix(runif(3), ncol = 1))
  weights1 <- matrix(runif(6), nrow = 2, ncol = 3)
  weights2 <- matrix(runif(2), nrow = 1, ncol = 2)
  layer1 <- Layer$new(weights1, MatrixOp$new()$sigmoid)
  layer2 <- Layer$new(weights2, MatrixOp$new()$relu)
  network <- NeuralNetwork$new(list(layer1, layer2))
  output <- network$forward_pass(input_data)
  print(output$data)
}

main()