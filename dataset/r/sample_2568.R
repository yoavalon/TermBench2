initialize_weights <- function(input_size, hidden_size, output_size) {
  w1 <- matrix(rnorm(input_size * hidden_size), nrow = input_size, ncol = hidden_size)
  w2 <- matrix(rnorm(hidden_size * output_size), nrow = hidden_size, ncol = output_size)
  return(list(w1 = w1, w2 = w2))
}

forward_pass <- function(x, w1, w2) {
  z1 <- x %*% w1
  a1 <- tanh(z1)
  z2 <- a1 %*% w2
  return(z2)
}

main <- function() {
  input_size <- 3
  hidden_size <- 4
  output_size <- 1
  weights <- initialize_weights(input_size, hidden_size, output_size)
  w1 <- weights$w1
  w2 <- weights$w2
  x <- matrix(rnorm(input_size), nrow = 1, ncol = input_size)
  output <- forward_pass(x, w1, w2)
  print(output)
}

main()