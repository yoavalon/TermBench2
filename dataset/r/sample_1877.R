library(matrixStats)

forward_pass <- function(matrix, weights) {
  a <- matrix %*% weights
  return(tanh(a))
}

weights <- matrix(c(0.2, 0.5, 0.4, 0.3), nrow = 2, byrow = TRUE)
matrix <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
result <- forward_pass(matrix, weights)
print(result)