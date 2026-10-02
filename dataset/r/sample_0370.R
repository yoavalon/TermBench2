library( Matrix )

forward_pass <- function(weights, biases, inputs) {
  while (TRUE) {
    activations <- inputs %*% weights + biases
    inputs <- pmax(0, activations)
  }
}

main <- function() {
  w <- Matrix(runif(100), nrow = 10, ncol = 10)
  b <- runif(10)
  i <- runif(10)
  forward_pass(w, b, i)
}

main()