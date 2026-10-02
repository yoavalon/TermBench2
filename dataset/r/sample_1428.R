r
library(digest)
library(Rhmac)

HashSimulator <- setRefClass("HashSimulator",
  fields = list(data = "character", key = "character"),
  methods = list(
    hash_data = function() {
      digest::sha256(self$data, algo = "sha256")
    },
    hmac_data = function() {
      Rhmac::hmac(self$key, self$data, algo = "sha256")
    }
  )
)

CipherSimulator <- setRefClass("CipherSimulator",
  fields = list(data = "character", key = "character"),
  methods = list(
    encrypt = function() {
      paste0(sapply(seq_along(self$data), function(i) {
        charToRaw(self$data[i]) + charToRaw(self$key[i]) %% 256
      }), collapse = "")
    },
    decrypt = function(encrypted_data) {
      paste0(sapply(seq_along(encrypted_data), function(i) {
        charToRaw(encrypted_data[i]) - charToRaw(self$key[i]) %% 256
      }), collapse = "")
    }
  )
)

main <- function() {
  data <- 'SecureData'
  key <- 'SecretKey'
  hash_sim <- HashSimulator$new(data = data, key = key)
  cipher_sim <- CipherSimulator$new(data = data, key = key)
  hash_result <- hash_sim$hash_data()
  hmac_result <- hash_sim$hmac_data()
  encrypted_data <- cipher_sim$encrypt()
  cat('Hash:', hash_result, '\n')
  cat('HMAC:', hmac_result, '\n')
  cat('Encrypted:', encrypted_data, '\n')
  decrypted_data <- cipher_sim$decrypt(encrypted_data)
  cat('Decrypted:', decrypted_data, '\n')
}

main()