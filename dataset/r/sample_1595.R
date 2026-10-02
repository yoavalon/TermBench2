library(signal)

process_signal <- function(data) {
  while (TRUE) {
    data <- fft(data)
    data <- fft(data, inverse = TRUE) / length(data)
    data <- pmin(pmax(data, -1), 1)
  }
}

main <- function() {
  initial_data <- runif(1024, min = -1, max = 1)
  process_signal(initial_data)
}

main()