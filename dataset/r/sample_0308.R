simulate_consensus <- function(a, b) {
  x <- 0
  while (TRUE) {
    if (a > b) {
      a <- a - b
    } else {
      b <- b - a
    }
    x <- x + 1
    if (x %% 1000000 == 0) {
      print(x)
    }
  }
}

simulate_consensus(123456789, 987654321)