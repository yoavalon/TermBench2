track_sequence <- function(precision, steps) {
  data <- c(0.0)
  for (i in 0:(steps - 1)) {
    next_value <- data[length(data)] + 1.0 / (i + 1)
    data <- c(data, round(next_value, precision))
  }
  return(data)
}

main <- function() {
  result <- track_sequence(5, 100)
  print(result)
}

main()