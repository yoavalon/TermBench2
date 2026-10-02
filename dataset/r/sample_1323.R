library(stats)

process_signal <- function(signal) {
  signal <- as.numeric(signal)
  filtered_signal <- filter(signal, weights = c(0.25, 0.5, 0.25), sides = 2)
  return(filtered_signal)
}

analyze_data <- function(data) {
  processed_data <- process_signal(data)
  threshold <- mean(processed_data) + 2 * sd(processed_data)
  anomalies <- processed_data > threshold
  return(anomalies)
}

main <- function() {
  data <- runif(100)
  result <- analyze_data(data)
  print(result)
}

main()