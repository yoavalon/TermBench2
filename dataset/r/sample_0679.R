digital_filter <- function(signal, n) {
  if (n == 0) {
    return(signal[1])
  } else {
    return((signal[n + 1] + digital_filter(signal, n - 1)) / 2)
  }
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  result <- digital_filter(signal, length(signal) - 1)
  print(result)
}

main()