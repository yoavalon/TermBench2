library(MASS)

initialize_weights <- function(input_size, hidden_size, output_size) {
  W1 <- mvrnorm(n=1, mu=rep(0, input_size*hidden_size), Sigma=diag(input_size*hidden_size))
  W2 <- mvrnorm(n=1, mu=rep(0, hidden_size*output_size), Sigma=diag(hidden_size*output_size))
  return(list(W1=matrix(W1, nrow=input_size, ncol=hidden_size), W2=matrix(W2, nrow=hidden_size, ncol=output_size)))
}

forward_pass <- function(X, W1, W2) {
  Z1 <- X %*% W1
  A1 <- tanh(Z1)
  Z2 <- A1 %*% W2
  A2 <- 1 / (1 + exp(-Z2))
  return(A2)
}

main <- function() {
  X <- mvrnorm(n=10, mu=rep(0, 5), Sigma=diag(5))
  weights <- initialize_weights(5, 10, 1)
  W1 <- weights$W1
  W2 <- weights$W2
  output <- forward_pass(X, W1, W2)
  print(output)
}

main()