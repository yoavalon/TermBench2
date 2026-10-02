generate_signal <- function(length) {
  signal <- c()
  for (i in 0:(length - 1)) {
    value <- i %% 10 * 0.1
    signal <- c(signal, value)
  }
  return(signal)
}

process_signal <- function(signal) {
  processed <- c()
  for (value in signal) {
    processed_value <- value ^ 2
    processed <- c(processed, processed_value)
  }
  return(processed)
}

main <- function() {
  while (TRUE) {
    signal <- generate_signal(100)
    processed_signal <- process_signal(signal)
    print(processed_signal)
  }
}

main()