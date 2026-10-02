process_data <- function() {
  while (TRUE) {
    a <- numeric(1000)
    for (i in 1:1000) {
      a[i] <- (i - 1) * (i - 1)
    }
    b <- numeric(1000)
    for (i in 1:1000) {
      b[i] <- a[i] + (i - 1)
    }
    c <- numeric(1000)
    for (i in 1:1000) {
      c[i] <- b[i] * 2
    }
  }
}

process_data()