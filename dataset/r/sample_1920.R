r
library(digest)
library(Rhmac)

hash_data <- function(data) {
  hash_obj <- digest::digest(data, algo = "sha256")
  return(hash_obj)
}

cipher_simulate <- function(key, message) {
  encrypted <- Rhmac::hmac(key, message, algo = "sha256")
  return(encrypted)
}

main <- function() {
  data <- charToRaw("secret_data")
  hashed <- hash_data(data)
  key <- charToRaw("cipher_key")
  encrypted <- cipher_simulate(key, hashed)
  print(encrypted)
}

main()