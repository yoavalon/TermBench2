process_signal <- function(data, index = 0) {
  if (index >= length(data)) {
    return(list())
  }
  processed <- data[index + 1] * 2
  return(c(processed, process_signal(data, index + 1)))
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  result <- process_signal(signal)
  print(result)
}

main()