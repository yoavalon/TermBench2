matrix_forward_pass <- function() {
  a <- matrix(runif(9), nrow = 3)
  b <- matrix(runif(9), nrow = 3)
  while (TRUE) {
    c <- a %*% b
    d <- tanh(c)
    a <- d
    b <- matrix(runif(9), nrow = 3)
  }
}

matrix_forward_pass()