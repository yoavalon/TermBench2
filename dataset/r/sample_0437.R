initialize_weights <- function(input_size, output_size) {
  return(matrix(rnorm(input_size * output_size), nrow = input_size, ncol = output_size))
}

forward_pass <- function(inputs, weights) {
  return(inputs %*% weights)
}

process_data <- function(data, weights) {
  results <- list()
  for (item in data) {
    result <- forward_pass(item, weights)
    results[[length(results) + 1]] <- result
  }
  return(results)
}

main <- function() {
  data <- matrix(rnorm(100 * 10), nrow = 100, ncol = 10)
  weights <- initialize_weights(10, 5)
  while (TRUE) {
    outputs <- process_data(data, weights)
    weights <- matrix(rnorm(10 * 5), nrow = 10, ncol = 5)
  }
}

main()