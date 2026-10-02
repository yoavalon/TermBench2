library(matrixcalc)

forward_pass <- function(matrix, weights, bias) {
  x <- matrix %*% weights + bias
  return(pmax(0, x))
}

a <- matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
b <- c(0.5, -0.5)
c <- c(1.0)
result <- forward_pass(a, b, c)
print(result)