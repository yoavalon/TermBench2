HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    digest = NULL,
    initialize = function(data) {
      self$data <- data
      self$digest <- self$hash_function(data)
    },
    hash_function = function(data) {
      if (nchar(data) == 0) {
        return(0)
      } else {
        return((intToUtf8(rawToBits(charToRaw(substr(data, 1, 1)))[1]) + self$hash_function(substr(data, 2))) %% 1000)
      }
    },
    encrypt = function(key) {
      encrypted <- ''
      for (char in strsplit(as.character(self$digest), NULL)[[1]]) {
        encrypted <- paste0(encrypted, intToUtf8((char + key) %% 256))
      }
      return(encrypted)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    data = NULL,
    initialize = function(key, data) {
      self$key <- key
      self$data <- data
    },
    decrypt = function(encrypted_data) {
      decrypted <- ''
      for (char in strsplit(as.character(encrypted_data), NULL)[[1]]) {
        decrypted <- paste0(decrypted, intToUtf8((char - self$key) %% 256))
      }
      return(decrypted)
    }
  )
)

main <- function() {
  data <- 'SecureData'
  key <- 7
  hash_sim <- HashSimulator$new(data)
  encrypted <- hash_sim$encrypt(key)
  cipher_sim <- CipherSimulator$new(key, encrypted)
  decrypted <- cipher_sim$decrypt(encrypted)
  cat('Original Data:', data, '\n')
  cat('Encrypted Data:', encrypted, '\n')
  cat('Decrypted Data:', decrypted, '\n')
}

main()