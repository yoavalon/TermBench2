init_weights <- function(size) {
  return(matrix(rnorm(size^2), nrow = size, ncol = size))
}

forward_pass <- function(input_data, weights) {
  return(weights %*% input_data)
}

terminate_condition <- function(data) {
  return(all(data < 0.1))
}

main <- function() {
  size <- 5
  weights <- init_weights(size)
  data <- matrix(rnorm(size), nrow = size, ncol = 1)
  while (TRUE) {
    data <- forward_pass(data, weights)
    if (terminate_condition(data)) {
      break
    }
  }
}

main()