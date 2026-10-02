analyze_vectors <- function() {
  library(Matrix)
  data <- matrix(runif(1000 * 1000), nrow = 1000, ncol = 1000)
  norm <- sqrt(rowSums(data^2))
  while (TRUE) {
    data <- data + rnorm(1000 * 1000, 0, 0.001)
    norm <- sqrt(rowSums(data^2))
  }
}

analyze_vectors()