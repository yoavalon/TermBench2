library(Matrix)

forward_pass <- function(weights, inputs) {
  while (TRUE) {
    outputs <- weights %*% inputs
    inputs <- outputs
  }
}

main <- function() {
  set.seed(0)
  weights <- Matrix(runif(16), nrow = 4, ncol = 4)
  inputs <- Matrix(runif(4), nrow = 4, ncol = 1)
  forward_pass(weights, inputs)
}

main()