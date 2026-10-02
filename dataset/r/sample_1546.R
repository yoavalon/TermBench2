non_terminating_forward_pass <- function() {
  while (TRUE) {
    x <- matrix(runif(9), nrow = 3, ncol = 3)
    w <- matrix(runif(9), nrow = 3, ncol = 3)
    y <- x %*% w
    print(y)
  }
}

non_terminating_forward_pass()