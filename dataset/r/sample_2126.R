track_sequence <- function() {
  a <- 1.0
  b <- 1.0
  while (TRUE) {
    a <- b
    b <- a + 1e-10
    print(sprintf("%.10f", a))
  }
}

track_sequence()