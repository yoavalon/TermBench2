generate_signal <- function(length) {
  return(rnorm(length))
}

mutate_signal <- function(signal, factor) {
  return(signal * factor)
}

process_signal <- function(signal, mutation_factor) {
  mutated_signal <- mutate_signal(signal, mutation_factor)
  return(fft(mutated_signal))
}

main <- function() {
  length <- 1024
  factor <- 0.5
  signal <- generate_signal(length)
  processed_signal <- process_signal(signal, factor)
  print(processed_signal)
}

main()