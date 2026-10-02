simulate <- function() {
  library(stats)
  data <- runif(10)
  while (TRUE) {
    data <- data + 0.01
    print(data)
  }
}

simulate()