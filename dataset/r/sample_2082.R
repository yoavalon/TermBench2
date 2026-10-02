library(MASS)

Layer <- setRefClass("Layer",
  fields = list(
    weights = "matrix",
    bias = "matrix"
  ),
  methods = list(
    initialize = function(input_size, output_size) {
      .self$weights <- mvrnorm(1, rep(0, input_size * output_size), diag(input_size * output_size))
      .self$bias <- mvrnorm(1, rep(0, output_size), diag(output_size))
    },
    forward = function(x) {
      return (x %*% matrix(.self$weights, nrow = nrow(x), ncol = ncol(.self$weights), byrow = TRUE) + .self$bias)
    }
  )
)

relu <- function(x) {
  return (ifelse(x > 0, x, 0))
}

softmax <- function(x) {
  e_x <- exp(x - apply(x, 1, max))
  return (e_x / apply(e_x, 1, sum))
}

neural_network_forward_pass <- function(input_data, layers) {
  a <- input_data
  for (layer in layers) {
    a <- layer$forward(a)
    a <- relu(a)
  }
  return (softmax(a))
}

generate_data <- function(batch_size, input_size) {
  return (mvrnorm(batch_size, rep(0, input_size), diag(input_size)))
}

main <- function() {
  input_size <- 784
  hidden_size <- 256
  output_size <- 10
  batch_size <- 64
  layers <- list(Layer$new(input_size, hidden_size), Layer$new(hidden_size, output_size))
  input_data <- generate_data(batch_size, input_size)
  output <- neural_network_forward_pass(input_data, layers)
  print(output)
}

main()