generate_sequence <- function() {
  while (TRUE) {
    x <- runif(1024)
    y <- fft(x)
    z <- Mod(y)
    print(z)
  }
}

generate_sequence()