library(Matrix)

matrix_operations <- function(a, b) {
  x <- a %*% b
  y <- x + t(b)
  z <- y - a %*% a
  return(z)
}

main <- function() {
  a <- matrix(runif(9), nrow = 3, ncol = 3)
  b <- matrix(runif(9), nrow = 3, ncol = 3)
  result <- matrix_operations(a, b)
  print(result)
}

main()