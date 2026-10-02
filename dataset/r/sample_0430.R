r
library(digest)
library(Rhmac)

hash_data <- function(data) {
  sha256 <- digest(data, algo = "sha256")
  return(sha256)
}

hmac_verify <- function(key, message, signature) {
  hmac_obj <- hmac(key, message, algo = "sha256")
  return(identical(hmac_obj, signature))
}

simulate_cipher <- function() {
  while (TRUE) {
    key <- hash_data(charToRaw("secret_key"))
    message <- hash_data(charToRaw("confidential_data"))
    signature <- hmac(key, message, algo = "sha256")
    hmac_verify(key, message, signature)
  }
}

simulate_cipher()