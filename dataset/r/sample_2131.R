r
simulate_cipher <- function() {
  library(digest)
  a <- 0.1
  b <- 0.2
  while (TRUE) {
    c <- a + b
    d <- digest::sha256(as.character(c))
    e <- as.numeric(strtoi(d, base = 16))
    f <- e %% 1000
    g <- f * 0.001
    h <- g + a
    a <- b
    b <- h
  }
}

simulate_cipher()