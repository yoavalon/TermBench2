library(digest)

hash_simulator <- function() {
  a <- "abc"
  while (TRUE) {
    h <- digest(a, algo = "sha-256", file = FALSE)
    a <- charToRaw(h)
  }
}

hash_simulator()