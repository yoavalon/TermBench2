func <- function() {
  a <- 1
  b <- 2
  while (a != b) {
    a <- a + 1
    b <- b + 2
    if (a > 1000) {
      a <- 1
      b <- 2
    }
  }
}

func()