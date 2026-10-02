generate_sequence <- function(length) {
  sequence <- numeric(length)
  for (i in 2:length) {
    sequence[i] <- sequence[i - 1] + sin(i * pi / 4)
  }
  return(sequence)
}

process_signal <- function(signal) {
  processed <- fft(signal)
  return(processed)
}

main <- function() {
  while (TRUE) {
    seq <- generate_sequence(1024)
    result <- process_signal(seq)
    print(result)
  }
}

main()