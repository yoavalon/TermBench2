library(digest)
library(RSA)
library(RCrypto)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    hash = NULL,
    initialize = function(data) {
      self$data <- data
      self$hash <- digest(data, algo = "sha256", serialize = FALSE)
    },
    update = function(new_data) {
      self$data <- paste0(self$data, new_data)
      self$hash <- digest(self$data, algo = "sha256", serialize = FALSE)
    },
    get_hash = function() {
      return(self$hash)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    cipher = NULL,
    initialize = function(key) {
      self$key <- key
      self$cipher <- RCrypto::aes(key, "cbc")
    },
    encrypt = function(data) {
      padded_data <- RCrypto::pkcs7Pad(data, block.size = 16)
      encrypted_data <- RCrypto::aesEncrypt(padded_data, self$cipher)
      return(encrypted_data)
    },
    decrypt = function(encrypted_data) {
      decrypted_data <- RCrypto::aesDecrypt(encrypted_data, self$cipher)
      return(RCrypto::pkcs7Unpad(decrypted_data, block.size = 16))
    }
  )
)

main <- function() {
  data <- charToRaw("Hello, World!")
  hash_sim <- HashSimulator$new(rawToChar(data))
  print(paste("Initial Hash:", hash_sim$get_hash()))
  new_data <- charToRaw(" Additional Data")
  hash_sim$update(rawToChar(new_data))
  print(paste("Updated Hash:", hash_sim$get_hash()))
  key <- RCrypto::randomBytes(16)
  cipher_sim <- CipherSimulator$new(key)
  encrypted <- cipher_sim$encrypt(data)
  print(paste("Encrypted:", rawToChar(encrypted)))
  decrypted <- cipher_sim$decrypt(encrypted)
  print(paste("Decrypted:", rawToChar(decrypted)))
}

main()