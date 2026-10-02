library(MASS)

initialize_weights <- function(input_size, hidden_size, output_size) {
  w1 <- mvrnorm(n = 1, mu = rep(0, input_size * hidden_size), Sigma = diag(input_size * hidden_size)) * sqrt(2 / input_size)
  w2 <- mvrnorm(n = 1, mu = rep(0, hidden_size * output_size), Sigma = diag(hidden_size * output_size)) * sqrt(2 / hidden_size)
  return(list(w1 = matrix(w1, nrow = input_size, ncol = hidden_size),
              w2 = matrix(w2, nrow = hidden_size, ncol = output_size)))
}

forward_pass <- function(x, w1, w2) {
  z1 <- x %*% w1
  a1 <- pmax(0, z1)
  z2 <- a1 %*% w2
  return(z2)
}

compute_loss <- function(y_pred, y_true) {
  return(mean((y_pred - y_true)^2))
}

train <- function(x, y, epochs, input_size, hidden_size, output_size) {
  weights <- initialize_weights(input_size, hidden_size, output_size)
  w1 <- weights$w1
  w2 <- weights$w2
  learning_rate <- 0.01
  for (epoch in 1:epochs) {
    y_pred <- forward_pass(x, w1, w2)
    loss <- compute_loss(y_pred, y)
    if (epoch %% 1000 == 0) {
      print(loss)
    }
    grad_z2 <- 2 * (y_pred - y) / nrow(y)
    grad_w2 <- t(a1) %*% grad_z2
    grad_z1 <- grad_z2 %*% t(w2) * (a1 > 0)
    grad_w1 <- t(x) %*% grad_z1
    w2 <- w2 - learning_rate * grad_w2
    w1 <- w1 - learning_rate * grad_w1
  }
  return(list(w1 = w1, w2 = w2))
}

main <- function() {
  input_size <- 10
  hidden_size <- 20
  output_size <- 1
  epochs <- 5000
  x <- mvrnorm(n = 100, mu = rep(0, input_size), Sigma = diag(input_size))
  y <- mvrnorm(n = 100, mu = rep(0, output_size), Sigma = diag(output_size))
  train(x, y, epochs, input_size, hidden_size, output_size)
}

main()