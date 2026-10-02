library(matrixStats)

forward_pass <- function(matrix, weights, bias) {
  return(matrix %*% weights + bias)
}

recursive_forward <- function(matrix, weights_list, bias_list, index) {
  result <- forward_pass(matrix, weights_list[[index]], bias_list[[index]])
  if (index < length(weights_list)) {
    return(recursive_forward(result, weights_list, bias_list, index + 1))
  } else {
    return(recursive_forward(result, weights_list, bias_list, 1))
  }
}

main <- function() {
  data <- matrix(runif(50), nrow = 10, ncol = 5)
  weights <- lapply(1:3, function(_) matrix(runif(25), nrow = 5, ncol = 5))
  biases <- lapply(1:3, function(_) matrix(runif(5), nrow = 5, ncol = 1))
  recursive_forward(data, weights, biases, 1)
}

main()