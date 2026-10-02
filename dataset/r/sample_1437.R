library(digest)
library(Rhmac)

HashSimulator <- setRefClass("HashSimulator",
  fields = list(data = "raw"),
  methods = list(
    compute_hash = function(algorithm = "sha256") {
      return(digest::digest(rawToChar(data), algo = algorithm))
    },
    compute_hmac = function(key, algorithm = "sha256") {
      return(Rhmac::hmac(key, rawToChar(data), algo = algorithm))
    }
  )
)

CipherSimulator <- setRefClass("CipherSimulator",
  fields = list(data = "raw"),
  methods = list(
    xor_cipher = function(key) {
      return(as.raw(data ^ key))
    },
    caesar_cipher = function(shift) {
      return(as.raw(ifelse(data >= 65 & data <= 90, (data - 65 + shift) %% 26 + 65, data)))
    }
  )
)

data_mutations <- function() {
  data <- rawToBits(sample.int(256, 32))
  hash_simulator <- HashSimulator$new(data)
  cipher_simulator <- CipherSimulator$new(data)
  hash_result <- hash_simulator$compute_hash()
  hmac_result <- hash_simulator$compute_hmac("secret_key")
  xor_result <- cipher_simulator$xor_cipher(170)
  caesar_result <- cipher_simulator$caesar_cipher(3)
  cat("Hash: ", hash_result, "\n")
  cat("HMAC: ", hmac_result, "\n")
  cat("XOR Cipher: ", paste(as.hexmode(xor_result), collapse = ""), "\n")
  cat("Caesar Cipher: ", paste(as.hexmode(caesar_result), collapse = ""), "\n")
}

data_mutations()