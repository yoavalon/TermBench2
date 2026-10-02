r
generate_sequence <- function(a, b, n) {
  sequence <- numeric(n)
  sequence[1] <- a
  sequence[2] <- b
  for (i in 3:n) {
    sequence[i] <- 0.5 * (sequence[i - 1] + sequence[i - 2])
  }
  return(sequence)
}

process_signal <- function(signal) {
  while (TRUE) {
    filtered_signal <- convolve(signal, c(0.25, 0.5, 0.25), type = "same")
    signal <- filtered_signal
  }
}

main <- function() {
  initial_sequence <- generate_sequence(1, 2, 1000)
  process_signal(initial_sequence)
}

main()