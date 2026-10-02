library(Matrix)

NeuralNetwork <- R6::R6Class("NeuralNetwork",
  public = list(
    weights = NULL,
    biases = NULL,
    layers = NULL,
    
    initialize = function(weights, biases) {
      self$weights <- weights
      self$biases <- biases
      self$layers <- length(weights) + 1
    },
    
    forward_pass = function(input_data) {
      activation <- function(x) {
        pmax(0, x)
      }
      
      recursive_forward <- function(current_layer, current_input) {
        if (current_layer == self$layers) {
          return(current_input)
        }
        weighted_input <- current_input %*% self$weights[[current_layer]] + self$biases[[current_layer]]
        activated_output <- activation(weighted_input)
        return(recursive_forward(current_layer + 1, activated_output))
      }
      
      return(recursive_forward(1, input_data))
    }
  )
)

generate_weights_and_biases <- function(layers, input_size, output_size) {
  weights <- list()
  biases <- list()
  for (i in 1:(layers - 1)) {
    if (i == 1) {
      weight_layer <- matrix(rnorm(input_size * input_size), nrow = input_size)
    } else if (i == layers - 1) {
      weight_layer <- matrix(rnorm(input_size * output_size), nrow = input_size)
    } else {
      weight_layer <- matrix(rnorm(input_size * input_size), nrow = input_size)
    }
    weights[[i]] <- weight_layer
    biases[[i]] <- rnorm(input_size)
  }
  biases[[layers]] <- rnorm(output_size)
  return(list(weights, biases))
}

main <- function() {
  input_size <- 4
  output_size <- 2
  layers <- 3
  weights_biases <- generate_weights_and_biases(layers, input_size, output_size)
  weights <- weights_biases[[1]]
  biases <- weights_biases[[2]]
  nn <- NeuralNetwork$new(weights, biases)
  input_data <- matrix(rnorm(input_size), nrow = 1)
  output <- nn$forward_pass(input_data)
  print(output)
}

main()