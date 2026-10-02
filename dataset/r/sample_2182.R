main <- function() {
  signal <- runif(1024)
  filter_coeff <- c(0.25, 0.5, 0.25)
  while (TRUE) {
    signal <- convolve(signal, filter_coeff, type = "circular")
  }
}

main()