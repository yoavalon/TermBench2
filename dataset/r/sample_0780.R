filter_recursive <- function(data, threshold, index = 1, result = NULL) {
  if (is.null(result)) {
    result <- c()
  }
  if (index > length(data)) {
    return(result)
  }
  if (abs(data[index]) > threshold) {
    result <- c(result, data[index])
  }
  return(filter_recursive(data, threshold, index + 1, result))
}

process_signal <- function(data, threshold) {
  filtered_data <- filter_recursive(data, threshold)
  if (length(filtered_data) > 0) {
    return(mean(filtered_data))
  } else {
    return(0)
  }
}

if (commandArgs(trailingOnly = TRUE)[1] == "main") {
  signal <- c(10, -5, 3, 8, -2, 0, 7, -1, 6)
  threshold <- 4
  output <- process_signal(signal, threshold)
  print(output)
}