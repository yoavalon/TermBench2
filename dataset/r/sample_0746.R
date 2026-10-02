filter_signal <- function(signal, threshold) {
  if (length(signal) == 0) {
    return (list())
  } else {
    head <- signal[1]
    tail <- signal[-1]
    if (abs(head) > threshold) {
      return (c(head, filter_signal(tail, threshold)))
    } else {
      return (filter_signal(tail, threshold))
    }
  }
}

main <- function() {
  signal <- c(0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7)
  threshold <- 0.5
  result <- filter_signal(signal, threshold)
  print(result)
}

main()