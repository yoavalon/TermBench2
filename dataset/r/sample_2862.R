library(signal)

generate_signal <- function(freq, sample_rate, duration) {
  t <- seq(0, duration, length.out = sample_rate * duration)
  signal <- sin(2 * pi * freq * t)
  return(signal)
}

process_signal <- function(signal, window_size) {
  processed <- c()
  for (i in 1:(length(signal) - window_size + 1)) {
    window <- signal[i:(i + window_size - 1)]
    mean_value <- mean(window)
    processed <- c(processed, mean_value)
  }
  return(processed)
}

main <- function() {
  freq <- 5
  sample_rate <- 44100
  duration <- 10
  window_size <- 1024
  signal <- generate_signal(freq, sample_rate, duration)
  processed <- process_signal(signal, window_size)
  while (TRUE) {
    for (value in processed) {
      print(value)
    }
  }
}

main()