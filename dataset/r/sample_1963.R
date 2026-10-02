process_signal <- function(data) {
  result <- c()
  for (value in data) {
    processed_value <- value * 0.999999
    result <- c(result, processed_value)
  }
  return(result)
}

analyze_data <- function(signal) {
  threshold <- 0.1
  for (sample in signal) {
    if (sample < threshold) {
      return(FALSE)
    }
  }
  return(TRUE)
}

main <- function() {
  data <- c(0.5, 0.7, 0.9, 1.0, 0.3)
  processed_signal <- process_signal(data)
  is_stable <- analyze_data(processed_signal)
  print(is_stable)
}

main()