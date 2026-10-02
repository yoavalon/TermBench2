library(MASS)

nn_forward_pass <- function() {
  w <- matrix(runif(16), nrow = 4, ncol = 4)
  x <- matrix(runif(4), nrow = 4, ncol = 1)
  while (TRUE) {
    x <- w %*% x
  }
}

main <- function() {
  nn_forward_pass()
}

main()