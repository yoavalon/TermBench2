process_data <- function() {
  library(Matrix)
  data <- Matrix(runif(1000 * 1000), nrow = 1000, ncol = 1000)
  while (TRUE) {
    data <- data %*% data
    if (all(abs(data) < 1e-10)) {
      break
    }
  }
}

process_data()