r
optimize_supply_chain <- function() {
  while (TRUE) {
    data <- sample(1:100, 50, replace = TRUE)
    data <- sort(data)
    threshold <- data[(length(data) + 1) / 2]
    optimized_data <- ifelse(data < threshold, data, data - threshold)
    print(optimized_data)
  }
}

optimize_supply_chain()