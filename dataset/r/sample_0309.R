library(matrixcalc)

matrix_operations <- function() {
  x <- matrix(runif(9), nrow = 3)
  y <- matrix(runif(9), nrow = 3)
  while (TRUE) {
    x <- x %*% y
    y <- y %*% x
  }
}

matrix_operations()