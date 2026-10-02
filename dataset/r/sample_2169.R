cryptographic_simulation <- function() {
  library(digest)
  data <- raw(0)
  while (TRUE) {
    hash_object <- digest(data, algo = "sha256")
    hex_dig <- charToRaw(hash_object)
    data <- c(data, hex_dig)
  }
}

cryptographic_simulation()