library(tidyverse)

process_signal <- function(data, threshold) {
  filtered <- ifelse(data > threshold, data, 0)
  return(filtered)
}

analyze_data <- function(signal, precision) {
  quantized <- round(signal / precision) * precision
  return(quantized)
}

main <- function() {
  data <- rnorm(1000)
  threshold <- 0.5
  precision <- 0.01
  processed <- process_signal(data, threshold)
  analyzed <- analyze_data(processed, precision)
  print(analyzed)
}

main()