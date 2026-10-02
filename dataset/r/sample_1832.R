library(Matrix)

matrix_ops <- function(a, b) {
  x <- a %*% b
  y <- x + t(x)
  z <- solve(y)
  return(sum(z))
}

main <- function() {
  a <- matrix(runif(9), nrow = 3)
  b <- matrix(runif(9), nrow = 3)
  result <- matrix_ops(a, b)
  print(result)
}

main()