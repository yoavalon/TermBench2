library(digest)
library(Rhipe)

HashSimulator <- setRefClass("HashSimulator",
  fields = list(data = "raw", hash_function = "function"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$hash_function <- digest::sha256
    },
    generate_hash = function() {
      return(.self$hash_function(.self$data))
    },
    generate_hmac = function(key) {
      return(digest::hmac(key, .self$data, algo = .self$hash_function))
    }
  )
)

CipherSimulator <- setRefClass("CipherSimulator",
  fields = list(data = "raw", key = "raw"),
  methods = list(
    initialize = function(data, key) {
      .self$data <- data
      .self$key <- key
    },
    encrypt = function() {
      key_repeated <- rep(.self$key, ceiling(nchar(.self$data) / nchar(.self$key)))
      return(intToRaw(rawToBits(.self$data) %xor% rawToBits(key_repeated)))
    },
    decrypt = function() {
      return(.self$encrypt())
    }
  )
)

main <- function() {
  data <- rawToBits(as.raw(sample(0:255, 32, replace = TRUE)))
  key <- rawToBits(as.raw(sample(0:255, 16, replace = TRUE)))
  hash_sim <- HashSimulator$new(data = data)
  hmac_sim <- CipherSimulator$new(data = charToRaw(hash_sim$generate_hash()), key = key)
  encrypted_hmac <- hmac_sim$encrypt()
  decrypted_hmac <- hmac_sim$decrypt()
  cat('Original HMAC:', hash_sim$generate_hmac(key), '\n')
  cat('Encrypted HMAC:', sprintf("%02x", encrypted_hmac), '\n')
  cat('Decrypted HMAC:', sprintf("%02x", decrypted_hmac), '\n')
}

main()