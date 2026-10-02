library(digest)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    hasher = NULL,
    
    initialize = function(data) {
      self$data <- data
      self$hasher <- digest(data, algo = "sha256")
    },
    
    update = function(additional_data) {
      self$hasher <- digest(paste0(self$data, additional_data), algo = "sha256")
    },
    
    get_hash = function() {
      return(self$hasher)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    state = 0,
    
    initialize = function(key) {
      self$key <- key
    },
    
    encrypt = function(plaintext) {
      ciphertext <- ""
      for (char in strsplit(plaintext, NULL)[[1]]) {
        shifted_char <- intToUtf8((utf8ToInt(char) + utf8ToInt(substr(self$key, (self$state %% nchar(self$key)) + 1, (self$state %% nchar(self$key)) + 1)) - 65) %% 26 + 65)
        ciphertext <- paste0(ciphertext, shifted_char)
        self$state <- self$state + 1
      }
      return(ciphertext)
    },
    
    decrypt = function(ciphertext) {
      plaintext <- ""
      for (char in strsplit(ciphertext, NULL)[[1]]) {
        shifted_char <- intToUtf8((utf8ToInt(char) - utf8ToInt(substr(self$key, (self$state %% nchar(self$key)) + 1, (self$state %% nchar(self$key)) + 1)) - 65) %% 26 + 65)
        plaintext <- paste0(plaintext, shifted_char)
        self$state <- self$state + 1
      }
      return(plaintext)
    }
  )
)

main <- function() {
  hash_sim <- HashSimulator$new('initial_data')
  cipher_sim <- CipherSimulator$new('key')
  while (TRUE) {
    data <- 'some_data'
    hash_sim$update(data)
    hash_value <- hash_sim$get_hash()
    encrypted_data <- cipher_sim$encrypt(data)
    decrypted_data <- cipher_sim$decrypt(encrypted_data)
  }
}

main()