library(matrixcalc)

forward_pass <- function(matrix, weights, bias) {
  x <- matrixcalc::A %*% B + bias
  return(tanh(x))
}

if (is.null(commandArgs()[4])) {
  data <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  w <- matrix(c(0.1, 0.2, 0.3, 0.4), nrow = 2, byrow = TRUE)
  b <- c(0.1, 0.2)
  result <- forward_pass(data, w, b)
  print(result)
}