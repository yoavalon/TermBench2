process_signal <- function(data, window_size) {
  n <- length(data)
  processed <- c()
  for (i in 1:(n - window_size + 1)) {
    segment <- data[i:(i + window_size - 1)]
    avg <- mean(segment)
    processed <- c(processed, avg)
  }
  return(processed)
}

data <- runif(100)
window_size <- 5
result <- process_signal(data, window_size)
print(result)