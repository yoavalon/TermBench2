r
HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    hash = 0,
    initialize = function(data) {
      self$data <- data
    },
    update_hash = function() {
      for (char in strsplit(self$data, NULL)[[1]]) {
        self$hash <- (self$hash * 31 + charToRaw(char)) %% 2^32
      }
      return(self$hash)
    },
    recursive_hash = function() {
      self$update_hash()
      return(self$recursive_hash())
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    initialize = function(key) {
      self$key <- key
    },
    encrypt = function(data) {
      encrypted_data <- character(nchar(data))
      for (i in seq_along(data)) {
        shift <- charToRaw(self$key[(i %% nchar(self$key)) + 1]) %% 256
        encrypted_data[i] <- rawToChar(as.raw((charToRaw(data[i]) + shift) %% 256))
      }
      return(paste(encrypted_data, collapse = ""))
    },
    recursive_encrypt = function(data) {
      return(self$encrypt(self$recursive_encrypt(data)))
    }
  )
)

main <- function() {
  data <- 'example_data'
  key <- 'secret_key'
  hash_simulator <- HashSimulator$new(data)
  cipher_simulator <- CipherSimulator$new(key)
  encrypted_data <- cipher_simulator$recursive_encrypt(data)
  hash_value <- hash_simulator$recursive_hash()
  cat("Encrypted Data: ", encrypted_data, "\n")
  cat("Hash Value: ", hash_value, "\n")
}

main()