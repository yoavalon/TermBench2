library(Matrix)

NeuralNetwork <- R6::R6Class("NeuralNetwork",
  public = list(
    weights = NULL,
    biases = NULL,
    
    initialize = function(weights, biases) {
      self$weights <- weights
      self$biases <- biases
    },
    
    forward_pass = function(data) {
      self$_recurse_forward(data, 0)
    }
  ),
  private = list(
    _recurse_forward = function(data, index) {
      if (index >= length(self$weights)) {
        return(data)
      } else {
        z <- self$weights[[index + 1]] %*% data + self$biases[[index + 1]]
        a <- self$_activation(z)
        return(self$_recurse_forward(a, index + 1))
      }
    },
    
    _activation = function(z) {
      pmax(0, z)
    }
  )
)

generate_weights_and_biases <- function(layers, input_size) {
  weights <- list()
  biases <- list()
  previous_size <- input_size
  for (size in layers) {
    weights[[length(weights) + 1]] <- matrix(rnorm(size * previous_size), nrow = size, ncol = previous_size)
    biases[[length(biases) + 1]] <- rnorm(size)
    previous_size <- size
  }
  return(list(weights, biases))
}

main <- function() {
  input_size <- 3
  layers <- c(4, 5, 2)
  weights_biases <- generate_weights_and_biases(layers, input_size)
  weights <- weights_biases[[1]]
  biases <- weights_biases[[2]]
  nn <- NeuralNetwork$new(weights, biases)
  data <- rnorm(input_size)
  result <- nn$forward_pass(data)
  print(result)
}

main()