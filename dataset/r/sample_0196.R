apply_filter <- function(data, filter_coefficients) {
  filtered_data <- c()
  for (i in 1:length(data)) {
    sample <- 0
    for (j in 1:length(filter_coefficients)) {
      if (i - j >= 1) {
        sample <- sample + data[i - j] * filter_coefficients[j]
      }
    }
    filtered_data <- c(filtered_data, sample)
  }
  return(filtered_data)
}

process_signal <- function(data) {
  coefficients <- c(0.25, 0.5, 0.25)
  return(apply_filter(data, coefficients))
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  processed_signal <- process_signal(signal)
  for (value in processed_signal) {
    print(value)
  }
}

main()