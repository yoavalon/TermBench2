r
library(Matrix)

MatrixOperations <- R6::R6Class("MatrixOperations",
  public = list(
    a = NULL,
    b = NULL,
    initialize = function(a, b) {
      self$a <- as.matrix(a)
      self$b <- as.matrix(b)
    },
    multiply = function() {
      return(self$a %*% self$b)
    },
    add = function() {
      return(self$a + self$b)
    },
    subtract = function() {
      return(self$a - self$b)
    }
  )
)

NeuralNetwork <- R6::R6Class("NeuralNetwork",
  public = list(
    weights = NULL,
    biases = NULL,
    initialize = function(weights, biases) {
      self$weights <- as.matrix(weights)
      self$biases <- as.matrix(biases)
    },
    forward_pass = function(input_data) {
      operations <- MatrixOperations$new(input_data, self$weights)
      weighted_sum <- operations$multiply()
      biased_sum <- operations$add(self$biases)
      return(self$activation_function(biased_sum))
    },
    activation_function = function(x) {
      return(pmax(0, x))
    }
  )
)

main <- function() {
  input_data <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  weights <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
  biases <- c(0.5, 0.6)
  nn <- NeuralNetwork$new(weights, biases)
  output <- nn$forward_pass(input_data)
  print(output)
}

main()