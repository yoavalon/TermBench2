library(Matrix)

forward_pass <- function(matrix, weights, bias) {
  return(matrix %*% weights + bias)
}

main <- function() {
  a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  w <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
  b <- c(0.5, 0.6)
  result <- forward_pass(a, w, b)
  print(result)
}

main()