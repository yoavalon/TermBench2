library(digest)

simulate_cipher <- function() {
  a <- charToRaw("initial data")
  while (TRUE) {
    a <- digest(a, algo = "sha256")
  }
}

simulate_cipher()