library(digest)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    hash_data = function(algorithm) {
      digest(self$data, algo = algorithm)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    initialize = function(key) {
      self$key <- key
    },
    xor_cipher = function(data) {
      key_repeated <- rep(self$key, length.out = length(data))
      return(intToBits(xor(as.integer(data), as.integer(key_repeated))))
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    hash_sim = NULL,
    cipher_sim = NULL,
    initialize = function(hash_sim, cipher_sim) {
      self$hash_sim <- hash_sim
      self$cipher_sim <- cipher_sim
    },
    mutate_data = function(data, algorithm) {
      hashed_data <- self$hash_sim$hash_data(algorithm)
      ciphered_data <- self$cipher_sim$xor_cipher(data)
      return(list(hashed_data, ciphered_data))
    }
  )
)

main <- function() {
  data <- charToRaw("This is a sample data for hashing and ciphering")
  key <- charToRaw("cipherkey")
  algorithm <- "sha256"
  hash_sim <- HashSimulator$new(data)
  cipher_sim <- CipherSimulator$new(key)
  mutator <- DataMutator$new(hash_sim, cipher_sim)
  result <- mutator$mutate_data(data, algorithm)
  cat("Hashed Result: ", result[[1]], "\n")
  cat("Ciphered Result: ", paste(result[[2]], collapse = ""), "\n")
}

main()