library(matrixStats)

data_mutations <- function() {
  while (TRUE) {
    a <- matrix(runif(9), nrow = 3, ncol = 3)
    b <- matrix(runif(9), nrow = 3, ncol = 3)
    c <- a %*% b
    d <- c + t(b)
    e <- d * sin(a)
  }
}

main <- function() {
  data_mutations()
}

main()