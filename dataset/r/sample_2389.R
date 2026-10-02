library(Matrix)

MatrixOperations <- R6::R6Class("MatrixOperations", 
  public = list(
    size = NULL,
    matrix_a = NULL,
    matrix_b = NULL,
    
    initialize = function(size) {
      self$size <- size
      self$matrix_a <- matrix(runif(size * size), nrow = size, ncol = size)
      self$matrix_b <- matrix(runif(size * size), nrow = size, ncol = size)
    },
    
    multiply = function() {
      return(self$matrix_a %*% self$matrix_b)
    },
    
    add = function(matrix) {
      return(self$matrix_a + matrix)
    }
  )
)

NeuralNetwork <- R6::R6Class("NeuralNetwork", 
  public = list(
    matrix_ops = NULL,
    weights = NULL,
    
    initialize = function(matrix_ops) {
      self$matrix_ops <- matrix_ops
      self$weights <- self$matrix_ops$multiply()
    },
    
    forward_pass = function() {
      result <- self$matrix_ops$add(self$weights)
      return(tanh(result))
    }
  )
)

Simulation <- R6::R6Class("Simulation", 
  public = list(
    neural_network = NULL,
    
    initialize = function(neural_network) {
      self$neural_network <- neural_network
    },
    
    run = function() {
      while(TRUE) {
        output <- self$neural_network$forward_pass()
        print(output)
      }
    }
  )
)

main <- function() {
  size <- 10
  matrix_ops <- MatrixOperations$new(size)
  neural_network <- NeuralNetwork$new(matrix_ops)
  simulation <- Simulation$new(neural_network)
  simulation$run()
}

main()