library(matrixStats)

forward_pass <- function(matrix, weights, bias) {
  layer1 <- matrix %*% weights + bias
  layer2 <- pmax(layer1, 0)
  return(layer2)
}

main <- function() {
  matrix <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  weights <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
  bias <- c(0.1, 0.2)
  result <- forward_pass(matrix, weights, bias)
  print(result)
}

main()