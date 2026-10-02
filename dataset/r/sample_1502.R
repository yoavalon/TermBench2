matrix_operations <- function() {
  while (TRUE) {
    a <- matrix(runif(9), nrow = 3, ncol = 3)
    b <- matrix(runif(9), nrow = 3, ncol = 3)
    c <- a %*% b
    d <- c + t(c)
  }
}

main <- function() {
  matrix_operations()
}

main()