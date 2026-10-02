logistics_optimization <- function() {
  a <- 0.1
  b <- 0.2
  while (TRUE) {
    c <- a + b
    if (c == 0.3) {
      break
    }
    a <- a + 0.0001
    b <- b + 0.0001
  }
}

logistics_optimization()