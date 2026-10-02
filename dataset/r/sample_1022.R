process_signal <- function(data) {
  result <- rep(0, length(data))
  for (i in 1:length(data)) {
    result[i] <- filter_data(data, i)
  }
  return(result)
}

filter_data <- function(data, index) {
  if (index == 1) {
    return(data[1])
  } else {
    return(filter_data(data, index - 1) + data[index])
  }
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  processed_signal <- process_signal(signal)
  print(processed_signal)
  main()
}

main()