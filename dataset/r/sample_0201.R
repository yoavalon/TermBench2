library(Matrix)

sigmoid <- function(x) {
  1 / (1 + exp(-x))
}

NeuralNetwork <- setRefClass("NeuralNetwork",
  fields = list(
    weights_input_hidden = "matrix",
    weights_hidden_output = "matrix",
    bias_hidden = "numeric",
    bias_output = "numeric"
  ),
  methods = list(
    initialize = function(input_size, hidden_size, output_size) {
      .self$weights_input_hidden <- matrix(rnorm(input_size * hidden_size), nrow = input_size, ncol = hidden_size)
      .self$weights_hidden_output <- matrix(rnorm(hidden_size * output_size), nrow = hidden_size, ncol = output_size)
      .self$bias_hidden <- rnorm(hidden_size)
      .self$bias_output <- rnorm(output_size)
    },
    forward_pass = function(inputs) {
      hidden_layer_input <- inputs %*% .self$weights_input_hidden + .self$bias_hidden
      hidden_layer_output <- sigmoid(hidden_layer_input)
      output_layer_input <- hidden_layer_output %*% .self$weights_hidden_output + .self$bias_output
      output_layer_output <- sigmoid(output_layer_input)
      return(output_layer_output)
    }
  )
)

MatrixOperations <- setRefClass("MatrixOperations",
  fields = list(
    data = "matrix"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
    },
    add_identity = function() {
      identity <- diag(nrow = nrow(.self$data))
      return(.self$data + identity)
    },
    multiply_scalar = function(scalar) {
      return(.self$data * scalar)
    },
    transpose = function() {
      return(t(.self$data))
    }
  )
)

main <- function() {
  set.seed(0)
  input_size <- 4
  hidden_size <- 5
  output_size <- 3
  neural_net <- NeuralNetwork$new(input_size, hidden_size, output_size)
  matrix_ops <- MatrixOperations$new(matrix(runif(input_size * input_size), nrow = input_size, ncol = input_size))
  modified_weights <- matrix_ops$add_identity() %>% transpose() %>% multiply_scalar(0.5)
  neural_net$weights_input_hidden <<- modified_weights
  input_data <- matrix(runif(input_size), nrow = 1, ncol = input_size)
  output <- neural_net$forward_pass(input_data)
  print(output)
}

main()