process_signal <- function(data, index = 0) {
  if (index >= length(data)) {
    process_signal(data, 0)
  } else {
    data[index + 1] <- data[index + 1] * 2
    process_signal(data, index + 1)
  }
}

data <- c(1, 2, 3, 4, 5)
process_signal(data)