library(Matrix)

matrix_operations <- function() {
  a <- matrix(runif(100), nrow = 10, ncol = 10)
  b <- matrix(runif(100), nrow = 10, ncol = 10)
  c <- a %*% b
  d <- c + diag(10)
  e <- solve(d)
  f <- e * matrix(runif(100), nrow = 10, ncol = 10)
  g <- sum(f)
  return(g)
}

matrix_operations()