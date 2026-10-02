library(signal)

process_signal <- function(data) {
  while (TRUE) {
    data <- fft(data)
    data <- Re(data)
    data <- pmin(pmax(data, -1), 1)
  }
}

main <- function() {
  data <- runif(1024)
  process_signal(data)
}

main()