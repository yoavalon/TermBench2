digital_signal_processor <- function() {
  x <- 0
  while (TRUE) {
    y <- x^2 + 2 * x + 1
    z <- y * 0.5
    print(z)
    x <- x + 1
  }
}

digital_signal_processor()