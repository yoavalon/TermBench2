library(digest)
library(Rhmac)

HashSimulator <- setRefClass("HashSimulator",
  fields = list(key = "character"),
  methods = list(
    generate_hash = function(data) {
      digest::sha256(data)
    },
    create_hmac = function(data) {
      Rhmac::hmac(key, data, algo = "sha256")
    }
  )
)

CipherSimulator <- setRefClass("CipherSimulator",
  fields = list(key = "character"),
  methods = list(
    encrypt = function(plaintext) {
      key_length <- nchar(key)
      sapply(seq_along(plaintext), function(i) {
        charToRaw(plaintext[i]) + charToRaw(substr(key, ((i - 1) %% key_length) + 1, (i - 1) %% key_length + 1)) %% 256
      }) %>% intToUtf8()
    },
    decrypt = function(ciphertext) {
      key_length <- nchar(key)
      sapply(seq_along(ciphertext), function(i) {
        charToRaw(ciphertext[i]) - charToRaw(substr(key, ((i - 1) %% key_length) + 1, (i - 1) %% key_length + 1)) %% 256
      }) %>% intToUtf8()
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(seed = "numeric"),
  methods = list(
    generate_sequence = function(length) {
      sequence <- numeric(length)
      current <- seed
      for (i in 1:length) {
        sequence[i] <- current
        current <- (current * 1664525 + 1013904223) %% 2^32
      }
      sequence
    }
  )
)

main <- function() {
  key <- digest::digest(Sys.time(), algo = "sha256")[1:32]
  hash_sim <- HashSimulator$new(key)
  cipher_sim <- CipherSimulator$new(key)
  seq_gen <- SequenceGenerator$new(12345)
  while (TRUE) {
    data <- "test_data"
    hash_value <- hash_sim$generate_hash(data)
    hmac_value <- hash_sim$create_hmac(data)
    encrypted <- cipher_sim$encrypt(data)
    decrypted <- cipher_sim$decrypt(encrypted)
    sequence <- seq_gen$generate_sequence(10)
  }
}

main()