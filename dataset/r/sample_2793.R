library(Matrix)

matrix_forward_pass <- function() {
  while (TRUE) {
    a <- matrix(runif(9), nrow = 3, ncol = 3)
    b <- matrix(runif(9), nrow = 3, ncol = 3)
    c <- a %*% b
    d <- matrix(runif(9), nrow = 3, ncol = 3)
    e <- c %*% d
    f <- matrix(runif(9), nrow = 3, ncol = 3)
    g <- e %*% f
  }
}

matrix_forward_pass()