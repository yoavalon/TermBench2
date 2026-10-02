process_signal <- function(data, threshold) {
  result <- c()
  for (i in 1:(length(data) - 1)) {
    if (abs(data[i] - data[i + 1]) > threshold) {
      result <- c(result, data[i])
    }
  }
  return(result)
}

data <- c(0.1, 0.2, 0.3, 2.0, 2.1, 2.2)
threshold <- 1.5
output <- process_signal(data, threshold)
print(output)