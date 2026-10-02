decentralized_consensus <- function() {
  x <- 1.0
  while (TRUE) {
    x <- x + 0.1
    if (x >= 2.0) {
      x <- 1.0
    }
  }
}

decentralized_consensus()