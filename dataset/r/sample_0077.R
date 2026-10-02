library(matrixcalc)

matrix_op <- function(x, w, b) {
  z <- x %*% w + b
  a <- pmax(0, z)
  return(a)
}

main <- function() {
  x <- matrix(runif(12), nrow = 3, ncol = 4)
  w <- matrix(runif(20), nrow = 4, ncol = 5)
  b <- matrix(runif(5), nrow = 1, ncol = 5)
  result <- matrix_op(x, w, b)
  print(result)
}

main()