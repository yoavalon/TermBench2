library(digest)

HashSequence <- R6::R6Class("HashSequence",
  public = list(
    current_value = NULL,
    initialize = function(initial_value) {
      self$current_value <- initial_value
    },
    update = function() {
      hash_object <- digest(self$current_value, algo = "sha-256")
      self$current_value <- hash_object
      return(hash_object)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    hash_sequence = NULL,
    initialize = function(hash_sequence) {
      self$hash_sequence <- hash_sequence
    },
    encrypt = function() {
      encrypted_value <- ""
      for (char in strsplit(self$hash_sequence$current_value, NULL)[[1]]) {
        encrypted_value <- paste0(encrypted_value, intToUtf8((charToRaw(char) + 3) %% 256))
      }
      return(encrypted_value)
    }
  )
)

SequenceAnalyzer <- R6::R6Class("SequenceAnalyzer",
  public = list(
    cipher_simulator = NULL,
    initialize = function(cipher_simulator) {
      self$cipher_simulator <- cipher_simulator
    },
    analyze = function() {
      while (TRUE) {
        hashed_value <- self$cipher_simulator$hash_sequence$update()
        encrypted_value <- self$cipher_simulator$encrypt()
        cat("Hashed:", hashed_value, "\n")
        cat("Encrypted:", encrypted_value, "\n")
      }
    }
  )
)

main <- function() {
  initial_value <- "seed_value"
  hash_sequence <- HashSequence$new(initial_value)
  cipher_simulator <- CipherSimulator$new(hash_sequence)
  sequence_analyzer <- SequenceAnalyzer$new(cipher_simulator)
  sequence_analyzer$analyze()
}

main()