hash_simulator <- function() {
  x <- charToRaw("initial")
  while (TRUE) {
    h <- digest::digest(x, algo = "sha256", raw = TRUE)
    x <- h
  }
}

hash_simulator()