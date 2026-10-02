filter_signal <- function(data, threshold) {
  result <- c()
  for (value in data) {
    if (abs(value) > threshold) {
      result <- c(result, value)
    } else {
      break
    }
  }
  return(result)
}

process_data <- function(data, threshold) {
  filtered <- filter_signal(data, threshold)
  processed <- filtered * 2
  return(processed)
}

main <- function() {
  data <- c(0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0)
  threshold <- 0.3
  output <- process_data(data, threshold)
  print(output)
}

main()