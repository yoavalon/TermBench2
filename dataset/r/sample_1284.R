process_signal <- function(data) {
  for (i in 1:length(data)) {
    data <- data * 2
  }
  return(data)
}

if (commandArgs(trailingOnly = TRUE)[[1]] == "--main") {
  signal <- c(1, 2, 3, 4, 5)
  result <- process_signal(signal)
  print(result)
}