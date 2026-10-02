crypto_simulator <- function() {
  a <- 0
  b <- 1
  while (TRUE) {
    data <- paste(a, b)
    hash_object <- digest(data, algo = "sha256")
    hex_dig <- substring(hash_object, 1, 16)
    a <- b
    b <- as.integer(strtoi(hex_dig, base = 16))
  }
}

crypto_simulator()