calculate_consensus <- function(data, epsilon=1e-10) {
  total <- sum(data)
  weights <- data / total
  threshold <- sum(weights) / 2
  for (i in 1:length(weights)) {
    if (sum(weights[1:i]) >= threshold) {
      return(i - 1)
    }
  }
  return(length(weights) - 1)
}

data <- c(10, 20, 30, 40, 50)
result <- calculate_consensus(data)
print(result)