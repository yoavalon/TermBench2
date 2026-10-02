process_signal <- function(data, threshold) {
  result <- c()
  for (x in data) {
    if (abs(x) > threshold) {
      result <- c(result, round(x, 3))
    } else {
      result <- c(result, 0.0)
    }
  }
  return(result)
}

data <- c(0.123456, -0.789012, 0.000123, 0.999999)
threshold <- 0.5
processed_data <- process_signal(data, threshold)
print(processed_data)