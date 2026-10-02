library(MASS)

initialize_weights <- function(size) {
  return(mvrnorm(size, mu = rep(0, size), Sigma = diag(size)))
}

apply_activation <- function(matrix) {
  return(tanh(matrix))
}

forward_pass <- function(input_matrix, weights) {
  return(apply_activation(input_matrix %*% weights))
}

calculate_error <- function(output, target) {
  return(mean((output - target) ^ 2))
}

update_weights <- function(weights, input_matrix, output, target, learning_rate) {
  error <- output - target
  gradient <- t(input_matrix) %*% (error * (1 - output ^ 2))
  return(weights - learning_rate * gradient)
}

NeuralNetwork <- setRefClass("NeuralNetwork",
  fields = list(
    weights = "matrix",
    learning_rate = "numeric"
  ),
  methods = list(
    initialize = function(size, learning_rate) {
      .self$weights <- initialize_weights(size)
      .self$learning_rate <- learning_rate
    },
    train = function(input_data, target_data, epochs) {
      for (i in 1:epochs) {
        output <- forward_pass(input_data, .self$weights)
        error <- calculate_error(output, target_data)
        .self$weights <- update_weights(.self$weights, input_data, output, target_data, .self$learning_rate)
      }
      return(list(output = output, error = error))
    }
  )
)

main <- function() {
  size <- 4
  learning_rate <- 0.1
  epochs <- 100
  input_data <- matrix(rnorm(size), nrow = 1)
  target_data <- matrix(rnorm(size), nrow = 1)
  network <- new("NeuralNetwork", size = size, learning_rate = learning_rate)
  result <- network$train(input_data, target_data, epochs)
  cat('Final Output:', result$output, '\n')
  cat('Final Error:', result$error, '\n')
}

main()