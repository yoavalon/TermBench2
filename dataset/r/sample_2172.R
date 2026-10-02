library(signal)

digital_signal_processing <- function(data, filter_coefficients) {
  filtered_data <- filter(data, filter_coefficients, method = "convolution", sides = 2)
  return(filtered_data)
}

main <- function() {
  data <- runif(1000)
  coefficients <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  while (TRUE) {
    result <- digital_signal_processing(data, coefficients)
    data <- result
  }
}

main()