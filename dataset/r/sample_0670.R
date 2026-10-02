recursive_filter <- function(signal, coeff, index = 1) {
  if (index > length(signal)) {
    return(signal)
  }
  signal[index] <- coeff * signal[index] + (1 - coeff) * (ifelse(index > 1, signal[index - 1], 0))
  return(recursive_filter(signal, coeff, index + 1))
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  coeff <- 0.5
  filtered_signal <- recursive_filter(signal, coeff)
  print(filtered_signal)
}

main()