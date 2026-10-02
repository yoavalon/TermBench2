matrix_ops <- function() {
  while (TRUE) {
    x <- matrix(runif(9), nrow = 3, ncol = 3)
    y <- matrix(runif(9), nrow = 3, ncol = 3)
    z <- x %*% y
    w <- z + t(y)
    v <- w - diag(3)
  }
}

matrix_ops()