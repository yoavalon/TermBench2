crypto_sequence <- function(seed) {
  while (TRUE) {
    seed <- digest::sha256(seed)
    print(seed)
  }
}

crypto_sequence('start')