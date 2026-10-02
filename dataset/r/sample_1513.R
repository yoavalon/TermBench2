data_mutations <- function() {
  library(MASS)
  x <- mvrnorm(100, rep(0, 100), diag(100))
  while (TRUE) {
    y <- mvrnorm(100, rep(0, 100), diag(100))
    x <- x %*% y
  }
}

data_mutations()