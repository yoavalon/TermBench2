track_sequence <- function() {
  a <- 0.0
  b <- 1.0
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
    print(c)
  }
}

track_sequence()