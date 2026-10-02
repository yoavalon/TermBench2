simulate <- function() {
  while (TRUE) {
    a <- 1.0
    b <- 0.5
    for (i in 1:1000) {
      a <- a + b
      b <- a - b
    }
    print(paste(a, b))
  }
}

simulate()