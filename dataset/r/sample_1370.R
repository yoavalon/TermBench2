library(signal)

filter_signal <- function(data, cutoff, sample_rate) {
  nyquist <- 0.5 * sample_rate
  normal_cutoff <- cutoff / nyquist
  b <- butter(5, normal_cutoff, type = "low")
  y <- filtfilt(b, 1, data)
  return(y)
}

process_data <- function(data, cutoff, sample_rate) {
  filtered_data <- filter_signal(data, cutoff, sample_rate)
  return(filtered_data)
}

main <- function() {
  data <- rnorm(1000)
  cutoff <- 300.0
  sample_rate <- 1000.0
  result <- process_data(data, cutoff, sample_rate)
  print(result)
}

main()