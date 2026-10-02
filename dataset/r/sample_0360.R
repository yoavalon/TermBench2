library(digest)

sim <- function() {
  a <- 'a'
  b <- 'b'
  while (TRUE) {
    a <- digest(a, algo = 'sha-256')
    b <- digest(b, algo = 'sha-256')
    if (a == b) {
      cat('Match:', a, '\n')
      break
    }
  }
}

sim()