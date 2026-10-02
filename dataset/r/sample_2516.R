generate_signal <- function(length) {
  signal <- c()
  for (i in 0:(length - 1)) {
    value <- (i * 3 + 2) %% 10
    signal <- c(signal, value)
  }
  return(signal)
}

process_signal <- function(signal) {
  filtered <- c()
  for (value in signal) {
    if (value > 5) {
      filtered <- c(filtered, value)
    }
  }
  return(filtered)
}

main <- function() {
  length <- 10
  signal <- generate_signal(length)
  result <- process_signal(signal)
  print(result)
}

main()