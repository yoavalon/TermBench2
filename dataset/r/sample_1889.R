process_signal <- function(data, factor) {
  result <- data * factor
  return(round(result, 5))
}

main <- function() {
  signal <- c(0.123456789, 0.23456789, 0.345678901)
  factor <- 1.23456
  processed <- process_signal(signal, factor)
  print(processed)
}

main()