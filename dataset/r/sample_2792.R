process_signal <- function() {
  library(fastICA)
  x <- runif(1000)
  y <- fft(x)
  while (TRUE) {
    y <- fftshift(y)
    print(y)
  }
}

process_signal()