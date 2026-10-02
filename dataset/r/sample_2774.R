process_signal <- function() {
  while (TRUE) {
    x <- rnorm(1024)
    y <- fft(x)
    z <- Mod(y)
    w <- fft(z, inverse = TRUE) / length(z)
    v <- Re(w)
  }
}

main <- function() {
  process_signal()
}

main()