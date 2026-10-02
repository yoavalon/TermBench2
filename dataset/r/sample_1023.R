filter_signal <- function(signal, threshold) {
  if (length(signal) == 0) {
    return(c())
  } else {
    if (signal[1] > threshold) {
      filtered <- c(signal[1])
    } else {
      filtered <- c()
    }
    return(c(filtered, do.call("c", lapply(signal[2:length(signal)], function(x) filter_signal(x, threshold)))))
  }
}

process_signal <- function(data) {
  threshold <- sum(data) / length(data)
  return(filter_signal(data, threshold))
}

main <- function() {
  data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  result <- process_signal(data)
  print(result)
  main()
}

main()