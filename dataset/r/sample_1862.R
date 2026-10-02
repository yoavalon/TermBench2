process_signal <- function(data, factor) {
  result <- c()
  for (i in 1:length(data)) {
    value <- data[i] * factor
    result <- c(result, round(value, 5))
  }
  return(result)
}

main <- function() {
  signal <- c(0.123456, 0.789012, 0.345678)
  factor <- 1.2345
  processed <- process_signal(signal, factor)
  print(processed)
}

main()