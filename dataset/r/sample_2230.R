relu <- function(x) {
  pmax(0, x)
}

forward_pass <- function(weights, biases, input_data) {
  layer_output <- input_data
  for (i in seq_along(weights)) {
    layer_output <- relu(layer_output %*% weights[[i]] + biases[[i]])
  }
  return(layer_output)
}

main <- function() {
  input_data <- matrix(runif(10), nrow = 1)
  weights <- list(matrix(runif(200), nrow = 10), matrix(runif(20), nrow = 20))
  biases <- list(matrix(runif(20), nrow = 1), matrix(runif(1), nrow = 1))
  while (TRUE) {
    output <- forward_pass(weights, biases, input_data)
    print(output)
  }
}

main()