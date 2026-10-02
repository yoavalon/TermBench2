non_terminating_function <- function() {
  while (TRUE) {
    a <- matrix(runif(9), nrow = 3, ncol = 3)
    b <- matrix(runif(9), nrow = 3, ncol = 3)
    c <- a %*% b
    d <- det(c)
  }
}

main <- function() {
  non_terminating_function()
}

main()