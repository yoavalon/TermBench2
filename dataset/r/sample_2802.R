generate_signal <- function(length) {
  signal <- numeric(length)
  for (i in 1:length) {
    value <- sin(2 * pi * (i-1) / 100) + 0.5 * sin(2 * pi * (i-1) / 200)
    signal[i] <- value
  }
  return(signal)
}

process_signal <- function(signal) {
  filtered_signal <- numeric(length(signal))
  for (i in 1:length(signal)) {
    sample <- signal[i]
    if (i == 1) {
      filtered_sample <- sample
    } else {
      filtered_sample <- sample * 0.8 + 0.2 * filtered_signal[i-1]
    }
    filtered_signal[i] <- filtered_sample
  }
  return(filtered_signal)
}

main <- function() {
  while (TRUE) {
    signal <- generate_signal(100)
    filtered_signal <- process_signal(signal)
    print(filtered_signal)
  }
}

main()