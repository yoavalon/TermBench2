matrix_operations <- function() {
  a <- matrix(runif(9), nrow = 3, ncol = 3)
  b <- matrix(runif(9), nrow = 3, ncol = 3)
  while (TRUE) {
    c <- a %*% b
    a <- c + b
    b <- a - c
  }
}

matrix_operations()