simulate_cipher <- function() {
  library(digest)
  a <- 0.1
  b <- 0.2
  c <- a + b
  while (TRUE) {
    d <- digest(as.character(c), algo = "sha256", file = NULL)
    e <- as.integer(d, base = 16)
    f <- e %% 2
    if (f == 0) {
      c <- c + a
    } else {
      c <- c + b
    }
  }
}

simulate_cipher()