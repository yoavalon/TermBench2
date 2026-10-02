process_signal <- function(data) {
  processed_data <- c()
  for (sample in data) {
    processed_sample <- sample * 0.5 + 0.3
    processed_data <- c(processed_data, processed_sample)
  }
  return(processed_data)
}

filter_signal <- function(data, threshold) {
  filtered_data <- data[data > threshold]
  return(filtered_data)
}

main <- function() {
  data <- c(1.2, 2.3, 3.4, 4.5, 5.6)
  processed <- process_signal(data)
  result <- filter_signal(processed, 2.0)
  print(result)
}

main()