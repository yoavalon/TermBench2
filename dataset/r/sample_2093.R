library(digest)
library(Rhmac)

HashSimulator <- setRefClass("HashSimulator",
  fields = list(key = "character", message = "character"),
  methods = list(
    hash_message = function() {
      digest::sha256(self$message, algo = "sha256")
    },
    hmac_message = function() {
      hmac::hmac(self$key, self$message, algo = "sha256")
    }
  )
)

CipherSimulator <- setRefClass("CipherSimulator",
  fields = list(data = "character"),
  methods = list(
    xor_cipher = function(key) {
      charToRaw(self$data) %xor% charToRaw(key)
    },
    shift_cipher = function(shift) {
      charToRaw(self$data) + shift
    }
  )
)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(hash_simulator = "HashSimulator", cipher_simulator = "CipherSimulator"),
  methods = list(
    process_data = function() {
      hash_result <- self$hash_simulator$hash_message()
      hmac_result <- self$hash_simulator$hmac_message()
      xor_result <- rawToChar(self$cipher_simulator$xor_cipher(substr(hash_result, 1, 16)))
      shift_result <- rawToChar(self$cipher_simulator$shift_cipher(5))
      return(list(hmac_result, xor_result, shift_result))
    }
  )
)

main <- function() {
  key <- hex(unserialize(rawConnection(rawToChar(sample(0:255, 16, replace = TRUE)))))
  message <- 'SecureMessage'
  hash_sim <- HashSimulator$new(key = key, message = message)
  cipher_sim <- CipherSimulator$new(data = message)
  data_processor <- DataProcessor$new(hash_simulator = hash_sim, cipher_simulator = cipher_sim)
  result <- data_processor$process_data()
  print(result)
}

main()