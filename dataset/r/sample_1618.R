filter_signal <- function(data, cutoff) {
  result <- c()
  for (x in data) {
    if (x > cutoff) {
      result <- c(result, x)
    }
  }
  return(result)
}

process_data <- function(stream, threshold) {
  while (TRUE) {
    filtered <- filter_signal(stream, threshold)
    print(filtered)
  }
}

main <- function() {
  data_stream <- c(1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1)
  threshold_value <- 2.0
  process_data(data_stream, threshold_value)
}

main()