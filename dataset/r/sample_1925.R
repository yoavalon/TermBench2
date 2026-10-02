track_sequence <- function(seq, precision) {
  result <- c()
  for (i in 1:(length(seq) - 1)) {
    diff <- abs(seq[i] - seq[i + 1])
    if (diff < precision) {
      result <- c(result, diff)
    }
  }
  return(result)
}

analyze_data <- function(data) {
  precision <- 1e-09
  processed_data <- track_sequence(data, precision)
  return(processed_data)
}

if (commandArgs(trailingOnly = TRUE)[1] == "") {
  data <- c(0.1, 0.2, 0.300000001, 0.4, 0.5)
  output <- analyze_data(data)
  print(output)
}