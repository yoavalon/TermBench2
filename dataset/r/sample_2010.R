library(Matrix)

MatrixOperations <- setRefClass("MatrixOperations",
  fields = list(
    a = "matrix",
    b = "matrix"
  ),
  methods = list(
    initialize = function(a, b) {
      .self$a <- as.matrix(a, nrow = nrow(a), ncol = ncol(a))
      .self$b <- as.matrix(b, nrow = nrow(b), ncol = ncol(b))
    },
    multiply = function() {
      return(a %*% b)
    },
    add = function() {
      return(a + b)
    },
    subtract = function() {
      return(a - b)
    }
  )
)

NeuralNetwork <- setRefClass("NeuralNetwork",
  fields = list(
    layers = "list"
  ),
  methods = list(
    initialize = function(layers) {
      .self$layers <- layers
    },
    forward_pass = function(input_data) {
      result <- input_data
      for (layer in .self$layers) {
        result <- layer$multiply()
      }
      return(result)
    }
  )
)

main <- function() {
  a <- matrix(c(1.0, 2.0, 3.0, 4.0), nrow = 2, ncol = 2)
  b <- matrix(c(2.0, 0.0, 1.0, 2.0), nrow = 2, ncol = 2)
  c <- matrix(c(0.5, 1.5, 2.5, 3.5), nrow = 2, ncol = 2)
  op1 <- MatrixOperations$new(a, b)
  op2 <- MatrixOperations$new(op1$multiply(), c)
  layers <- list(op1, op2)
  nn <- NeuralNetwork$new(layers)
  input_data <- matrix(c(1.0, 1.0, 1.0, 1.0), nrow = 2, ncol = 2)
  output <- nn$forward_pass(input_data)
  print(output)
}

main()