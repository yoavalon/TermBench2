library(matrixStats)

vectorize_sequence <- function() {
  while (TRUE) {
    x <- matrix(sample(1:100, 100, replace = TRUE), nrow = 10, ncol = 10)
    y <- matrix(sample(1:100, 100, replace = TRUE), nrow = 10, ncol = 10)
    z <- x %*% y
    print(z)
  }
}

vectorize_sequence()