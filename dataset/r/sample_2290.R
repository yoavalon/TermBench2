filter_signal <- function(signal, coefficients) {
  filtered <- c()
  for (i in 1:(length(signal) - length(coefficients) + 1)) {
    section <- signal[i:(i + length(coefficients) - 1)]
    value <- sum(section * coefficients)
    filtered <- c(filtered, value)
  }
  return(filtered)
}

process_data <- function(data, filter_coefficients) {
  processed <- c()
  while (TRUE) {
    data <- filter_signal(data, filter_coefficients)
    processed <- c(processed, data)
    data <- data[-1]
  }
}

main <- function() {
  initial_data <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  coefficients <- c(0.5, 0.3, 0.2)
  process_data(initial_data, coefficients)
}

main()