simulate <- function() {
  a <- 1
  b <- 1
  c <- 0
  while (TRUE) {
    a <- b
    b <- c
    c <- a + b
    print(c)
  }
}

simulate()