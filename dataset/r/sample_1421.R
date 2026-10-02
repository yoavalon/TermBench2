r
library(digest)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    hash_algorithms = NULL,
    initialize = function(data) {
      self$data <- data
      self$hash_algorithms <- c('md5', 'sha1', 'sha256', 'sha512')
    },
    apply_hash = function(algorithm) {
      digest::digest(self$data, algo = algorithm)
    },
    simulate_hashes = function() {
      results <- list()
      for (algo in self$hash_algorithms) {
        results[[algo]] <- self$apply_hash(algo)
      }
      return(results)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    data = NULL,
    key = NULL,
    initialize = function(data, key) {
      self$data <- data
      self$key <- key
    },
    xor_cipher = function() {
      encrypted <- raw(0)
      for (i in seq_along(self$data)) {
        if (is.raw(self$data[i])) {
          encrypted <- c(encrypted, as.raw(self$data[i] xor self$key[i %% length(self$key)]))
        } else {
          encrypted <- c(encrypted, as.raw(charToRaw(rawToChar(self$data[i])) xor self$key[i %% length(self$key)]))
        }
      }
      return(encrypted)
    },
    simulate_ciphers = function() {
      return(list(xor = self$xor_cipher()))
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    data = NULL,
    key = NULL,
    initialize = function(data) {
      self$data <- enc2utf8(charToRaw(data))
      self$key <- charToRaw('secret')
    },
    mutate = function() {
      hash_sim <- HashSimulator$new(self$data)
      cipher_sim <- CipherSimulator$new(self$data, self$key)
      hashes <- hash_sim$simulate_hashes()
      ciphers <- cipher_sim$simulate_ciphers()
      return(list(hashes = hashes, ciphers = ciphers))
    }
  )
)

main <- function() {
  data <- 'Sample data for cryptographic simulation'
  mutator <- DataMutator$new(data)
  result <- mutator$mutate()
  print(result)
}

main()