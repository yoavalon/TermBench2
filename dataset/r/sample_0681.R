process_signal <- function(data, index, threshold) {
  if (index >= length(data)) {
    return(data)
  }
  if (data[index] > threshold) {
    data[index] <- 0
  }
  return(process_signal(data, index + 1, threshold))
}

data <- c(10, 20, 30, 40, 50)
threshold <- 25
processed_data <- process_signal(data, 1, threshold)
print(processed_data)