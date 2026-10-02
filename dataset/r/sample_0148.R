process_signal <- function(data, threshold) {
  result <- c()
  for (value in data) {
    if (value > threshold) {
      result <- c(result, value)
    }
  }
  return(result)
}

analyze_data <- function(signal, boundary) {
  processed <- process_signal(signal, boundary)
  return(sum(processed))
}

main <- function() {
  data <- c(0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9)
  threshold <- 0.5
  result <- analyze_data(data, threshold)
  print(result)
}

main()