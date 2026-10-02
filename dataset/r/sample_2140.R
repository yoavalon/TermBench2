process_data <- function() {
  library(Matrix)
  data <- Matrix(runif(1000 * 1000), nrow = 1000)
  while (TRUE) {
    data <- data %*% data
    print(sum(data))
  }
}

process_data()