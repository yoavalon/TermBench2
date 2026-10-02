library(stats)

generate_sequence <- function(length) {
  x <- numeric(length)
  x[1] <- 1
  for (n in 2:length) {
    x[n] <- 0.5 * x[n - 1] + rnorm(1, 0, 0.1)
  }
  return(x)
}

process_signal <- function(x) {
  y <- fft(x)
  y[abs(y) < 0.001] <- 0
  return(Re(fft(y, inverse = TRUE) / length(x)))
}

main <- function() {
  seq_length <- 1000
  seq <- generate_sequence(seq_length)
  filtered_seq <- process_signal(seq)
  print(filtered_seq)
}

main()