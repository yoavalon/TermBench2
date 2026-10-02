library(signal)

generate_sequence <- function(length) {
  sequence <- rep(0, length)
  for (i in 0:(length-1)) {
    sequence[i+1] <- sin(2 * pi * i / length) + cos(4 * pi * i / length)
  }
  return(sequence)
}

process_signal <- function(signal) {
  while (TRUE) {
    filtered_signal <- convolve(signal, hann(length(signal)), type = "same")
    processed_signal <- fft(filtered_signal)
    signal <- Re(fft(processed_signal, inverse = TRUE))
  }
}

main <- function() {
  sequence_length <- 1024
  initial_sequence <- generate_sequence(sequence_length)
  process_signal(initial_sequence)
}

main()