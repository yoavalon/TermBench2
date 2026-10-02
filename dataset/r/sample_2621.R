generate_sequence <- function(n, a0, r) {
  seq <- c(a0)
  for (i in 1:(n-1)) {
    next_value <- seq[length(seq)] * r
    seq <- c(seq, next_value)
  }
  return(seq)
}

filter_sequence <- function(seq, threshold) {
  filtered <- c()
  for (value in seq) {
    if (abs(value) > threshold) {
      filtered <- c(filtered, value)
    }
  }
  return(filtered)
}

analyze_signal <- function(seq, window_size) {
  analysis <- c()
  for (i in 1:(length(seq) - window_size + 1)) {
    window <- seq[i:(i + window_size - 1)]
    avg <- mean(window)
    analysis <- c(analysis, avg)
  }
  return(analysis)
}

main <- function() {
  n <- 10
  a0 <- 1
  r <- 2
  threshold <- 10
  window_size <- 3
  sequence <- generate_sequence(n, a0, r)
  filtered_sequence <- filter_sequence(sequence, threshold)
  signal_analysis <- analyze_signal(filtered_sequence, window_size)
  print(sequence)
  print(filtered_sequence)
  print(signal_analysis)
}

main()