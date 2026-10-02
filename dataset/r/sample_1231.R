r
library(Matrix)

data_mutations <- function(matrix, weights, bias) {
  x <- matrix %*% weights + bias
  y <- tanh(x)
  return(y)
}

if (commandArgs()[4] == '--args') {
  a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  b <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
  c <- c(0.1, 0.2)
  result <- data_mutations(a, b, c)
  print(result)
}