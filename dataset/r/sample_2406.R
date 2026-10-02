process_signal <- function(data, threshold) {
  filtered <- c()
  for (val in data) {
    if (val > threshold) {
      filtered <- c(filtered, val)
    }
  }
  return(filtered)
}

if (is.null(commandArgs(trailingOnly = TRUE)[1])) {
  signal <- c(10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
  threshold <- 50
  result <- process_signal(signal, threshold)
  print(result)
}