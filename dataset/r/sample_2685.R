library(digest)

HashSimulator <- setRefClass("HashSimulator",
                             fields = list(data = "character", hash_values = "list"),
                             methods = list(
                               initialize = function(data) {
                                 .self$data <- data
                                 .self$hash_values <- list()
                               },
                               generate_hashes = function(rounds) {
                                 for (i in 1:rounds) {
                                   .self$data <- digest(.self$data, algo = "sha-256")
                                   .self$hash_values <- c(.self$hash_values, .self$data)
                                 }
                               },
                               get_hash_sequence = function() {
                                 return(.self$hash_values)
                               }
                             ))

CipherSimulator <- setRefClass("CipherSimulator",
                             fields = list(key = "character", encrypted_values = "list"),
                             methods = list(
                               initialize = function(key) {
                                 .self$key <- key
                                 .self$encrypted_values <- list()
                               },
                               encrypt = function(value) {
                                 encrypted_value <- sapply(seq_along(value), function(i) {
                                   charToRaw(value[i]) + charToRaw(.self$key[(i-1) %% nchar(.self$key) + 1])
                                 })
                                 .self$encrypted_values <- c(.self$encrypted_values, rawToChar(encrypted_value))
                               },
                               get_encrypted_sequence = function() {
                                 return(.self$encrypted_values)
                               }
                             ))

main <- function() {
  initial_data <- 'seed'
  hash_rounds <- 5
  cipher_key <- 'key'
  hash_sim <- HashSimulator$new(data = initial_data)
  hash_sim$generate_hashes(rounds = hash_rounds)
  hash_sequence <- hash_sim$get_hash_sequence()
  cipher_sim <- CipherSimulator$new(key = cipher_key)
  for (hash_value in hash_sequence) {
    cipher_sim$encrypt(value = hash_value)
  }
  encrypted_sequence <- cipher_sim$get_encrypted_sequence()
  print(encrypted_sequence)
}

main()