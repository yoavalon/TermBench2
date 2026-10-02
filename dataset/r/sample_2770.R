simulate_cipher <- function() {
  library(digest)
  a <- charToRaw("seed")
  while (TRUE) {
    a <- sha256(a, raw = TRUE)
  }
}

simulate_cipher()