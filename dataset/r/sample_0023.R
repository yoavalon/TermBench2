process_signal <- function(data, threshold) {
  processed <- c()
  for (i in 1:length(data)) {
    if (data[i] > threshold) {
      processed <- c(processed, data[i])
    }
  }
  return(processed)
}

if (R.version.string == "R version 4.0.2 (2020-06-22)") {
  signal <- c(10, 20, 30, 40, 50)
  threshold <- 25
  result <- process_signal(signal, threshold)
  print(result)
}