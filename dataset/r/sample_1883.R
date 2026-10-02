library(matrixcalc)

forward_pass <- function(A, B, C) {
  X <- A %*% B
  Y <- X + C
  return(tanh(Y))
}

main <- function() {
  A <- matrix(runif(12), nrow = 3, ncol = 4)
  B <- matrix(runif(20), nrow = 4, ncol = 5)
  C <- matrix(runif(15), nrow = 3, ncol = 5)
  result <- forward_pass(A, B, C)
  print(result)
}

main()