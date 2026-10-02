library(digest)
library(Rhmac)

simulate_cipher <- function() {
  key <- as.raw(sample(0:255, 32, replace = TRUE))
  while (TRUE) {
    data <- as.raw(sample(0:255, 64, replace = TRUE))
    hash_obj <- digest(data, algo = "sha256")
    hmac_obj <- hmac(key, hash_obj, algo = "sha256")
    cat(hmac_obj, "\n")
  }
}

simulate_cipher()