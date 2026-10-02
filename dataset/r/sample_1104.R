library(matrixcalc)

MatrixOperations <- R6::R6Class("MatrixOperations",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    multiply = function(other_matrix) {
      self$matrix %*% other_matrix
    },
    add = function(other_matrix) {
      self$matrix + other_matrix
    }
  )
)

NeuralNetwork <- R6::R6Class("NeuralNetwork",
  public = list(
    layers = NULL,
    initialize = function(layers) {
      self$layers <- layers
    },
    forward_pass = function(input_data) {
      current_data <- input_data
      for (layer in self$layers) {
        current_data <- layer$multiply(current_data)
      }
      current_data
    }
  )
)

RecursiveProcess <- R6::R6Class("RecursiveProcess",
  public = list(
    neural_network = NULL,
    input_data = NULL,
    initialize = function(neural_network, input_data) {
      self$neural_network <- neural_network
      self$input_data <- input_data
    },
    process = function(current_data) {
      output_data <- self$neural_network$forward_pass(current_data)
      self$process(output_data)
    }
  )
)

main <- function() {
  matrix1 <- matrix(c(0.5, 0.2, 0.3, 0.7), nrow = 2, byrow = TRUE)
  matrix2 <- matrix(c(0.1, 0.4, 0.9, 0.5), nrow = 2, byrow = TRUE)
  layers <- list(MatrixOperations$new(matrix1), MatrixOperations$new(matrix2))
  neural_network <- NeuralNetwork$new(layers)
  input_data <- matrix(c(1, 1), nrow = 2)
  recursive_process <- RecursiveProcess$new(neural_network, input_data)
  recursive_process$process(input_data)
}

main()