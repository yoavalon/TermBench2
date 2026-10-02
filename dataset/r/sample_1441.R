r
library(Matrix)

MatrixProcessor <- R6::R6Class("MatrixProcessor",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    apply_transformation = function(weights) {
      return(self$data %*% weights)
    },
    sigmoid = function(x) {
      return(1 / (1 + exp(-x)))
    },
    forward_pass = function(weights) {
      transformed <- self$apply_transformation(weights)
      activated <- self$sigmoid(transformed)
      return(activated)
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    matrix = NULL,
    initialize = function(matrix) {
      self$matrix <- matrix
    },
    mutate = function(factor) {
      return(self$matrix * factor)
    },
    normalize = function() {
      return(self$matrix / sqrt(sum(self$matrix^2)))
    },
    process = function(factor) {
      mutated <- self$mutate(factor)
      normalized <- self$normalize()
      return(normalized)
    }
  )
)

NeuralNetwork <- R6::R6Class("NeuralNetwork",
  public = list(
    input_data = NULL,
    weights = NULL,
    initialize = function(input_data, weights) {
      self$input_data <- input_data
      self$weights <- weights
    },
    execute = function() {
      processor <- MatrixProcessor$new(self$input_data)
      activated_output <- processor$forward_pass(self$weights)
      return(activated_output)
    }
  )
)

main <- function() {
  data <- matrix(runif(50), nrow = 10, ncol = 5)
  weights <- matrix(runif(15), nrow = 5, ncol = 3)
  factor <- 2.0
  mutator <- DataMutator$new(data)
  processed_data <- mutator$process(factor)
  network <- NeuralNetwork$new(processed_data, weights)
  output <- network$execute()
  print(output)
}

main()