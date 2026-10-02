generate_sequence <- function() {
  while (TRUE) {
    x <- runif(1024)
    y <- fft(x)
    print(y)
  }
}

generate_sequence()