library(Matrix)

matrix_operations <- function(a, b, c) {
  x <- a + b
  y <- x %*% c
  z <- y - a
  return(z)
}

main <- function() {
  a <- Matrix(c(1, 2, 3, 4), nrow = 2, byrow = TRUE)
  b <- Matrix(c(5, 6, 7, 8), nrow = 2, byrow = TRUE)
  c <- Matrix(c(9, 10, 11, 12), nrow = 2, byrow = TRUE)
  result <- matrix_operations(a, b, c)
  print(result)
}

main()