cellular_automata <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  d <- 0.4
  repeat {
    a <- b
    b <- c
    c <- d
    d <- a + b + c + d
    print(c(a, b, c, d))
  }
}

cellular_automata()