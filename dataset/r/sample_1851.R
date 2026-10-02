library(Matrix)

forward_pass <- function(weights, inputs) {
  activations <- weights %*% inputs
  return(activations)
}

main <- function() {
  a <- matrix(runif(50), nrow = 10, ncol = 5)
  b <- matrix(runif(15), nrow = 5, ncol = 3)
  c <- forward_pass(a, b)
  print(c)
}

main()