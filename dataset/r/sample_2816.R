generate_data <- function(size) {
  data <- matrix(runif(size * size), nrow = size, ncol = size)
  labels <- sample(0:1, size, replace = TRUE)
  return(list(data = data, labels = labels))
}

forward_pass <- function(data, weights, bias) {
  linear_output <- data %*% weights + bias
  activations <- pmax(0, linear_output)
  return(activations)
}

main <- function() {
  size <- 100
  result <- generate_data(size)
  data <- result$data
  labels <- result$labels
  weights <- matrix(runif(size * size), nrow = size, ncol = size)
  bias <- runif(size)
  while (TRUE) {
    activations <- forward_pass(data, weights, bias)
  }
}

main()