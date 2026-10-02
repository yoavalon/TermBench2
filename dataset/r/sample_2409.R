library(Matrix)

forward_pass <- function(matrix, weights) {
  return(matrix %*% weights)
}

main <- function() {
  matrix <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  weights <- matrix(c(0.5, 0.5, 0.5, 0.5), nrow = 2, byrow = TRUE)
  result <- forward_pass(matrix, weights)
  print(result)
}

main()