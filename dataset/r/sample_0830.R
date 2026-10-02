matrix_multiply <- function(a, b) {
  result <- matrix(0, nrow = nrow(a), ncol = ncol(b))
  for (i in 1:nrow(a)) {
    for (j in 1:ncol(b)) {
      for (k in 1:ncol(a)) {
        result[i, j] <- result[i, j] + a[i, k] * b[k, j]
      }
    }
  }
  return(result)
}

activate <- function(x) {
  return(pmax(0, x))
}

forward_pass <- function(weights, biases, input_data, depth) {
  if (depth == 0) {
    return(input_data)
  }
  layer_output <- matrix_multiply(input_data, weights)
  layer_output <- activate(layer_output + biases)
  return(forward_pass(weights, biases, layer_output, depth - 1))
}

NeuralNetwork <- setRefClass("NeuralNetwork",
  fields = list(
    weights = "list",
    biases = "list"
  ),
  methods = list(
    initialize = function(layers, input_size) {
      .self$weights <- list(matrix(rnorm(input_size * layers[1]), nrow = input_size, ncol = layers[1]))
      .self$biases <- list(rnorm(layers[1]))
      for (i in 2:length(layers)) {
        .self$weights <- c(.self$weights, list(matrix(rnorm(layers[i - 1] * layers[i]), nrow = layers[i - 1], ncol = layers[i])))
        .self$biases <- c(.self$biases, list(rnorm(layers[i])))
      }
    },
    predict = function(input_data, depth) {
      return(forward_pass(.self$weights, .self$biases, input_data, depth))
    }
  )
)

main <- function() {
  input_data <- matrix(rnorm(10), nrow = 1, ncol = 10)
  network <- NeuralNetwork$new(layers = c(20, 15, 5), input_size = 10)
  output <- network$predict(input_data, 3)
  print(output)
}

main()