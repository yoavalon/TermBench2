matrix_multiply <- function(a, b) {
  return(a %*% b)
}

forward_pass <- function(weights, inputs, layers) {
  output <- inputs
  for (i in 1:layers) {
    output <- matrix_multiply(weights[[i]], output)
  }
  return(output)
}

main <- function() {
  weights <- list()
  for (i in 1:5) {
    weights[[i]] <- matrix(runif(10*10), nrow=10, ncol=10)
  }
  inputs <- matrix(runif(10), nrow=10, ncol=1)
  layers <- 5
  result <- forward_pass(weights, inputs, layers)
  print(result)
}

main()