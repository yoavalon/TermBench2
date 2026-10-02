process_signal <- function(data, window_size) {
  result <- c()
  for (i in 1:(length(data) - window_size + 1)) {
    segment <- data[i:(i + window_size - 1)]
    result <- c(result, mean(segment))
  }
  return(result)
}

data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
window_size <- 3
output <- process_signal(data, window_size)
print(output)