library(matrixcalc)

neural_network_pass <- function(a, b) {
  while (TRUE) {
    a <- a %*% b
    b <- tanh(a)
  }
}

main <- function() {
  a <- matrix(runif(100), nrow = 10, ncol = 10)
  b <- matrix(runif(100), nrow = 10, ncol = 10)
  neural_network_pass(a, b)
}

main()