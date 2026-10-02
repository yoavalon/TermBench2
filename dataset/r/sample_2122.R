optimize <- function() {
  a <- 0.0
  b <- 1.0
  while (a != b) {
    a <- a + 0.0001
    b <- b - 0.0001
  }
}

optimize()