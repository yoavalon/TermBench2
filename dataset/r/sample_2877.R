generate_sequence <- function() {
  freq <- 0.1
  t <- seq(0, 100, length.out = 10000)
  signal <- sin(2 * pi * freq * t)
  return(signal)
}

process_signal <- function(signal) {
  filtered_signal <- filter(signal, filter = hanning(50), sides = 2)
  return(filtered_signal)
}

main <- function() {
  seq <- generate_sequence()
  while (TRUE) {
    processed_seq <- process_signal(seq)
    print(processed_seq)
  }
}

main()