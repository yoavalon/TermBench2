library(digest)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    depth = NULL,
    current_depth = 0,
    
    initialize = function(data, depth) {
      self$data <- data
      self$depth <- depth
    },
    
    hash_data = function() {
      return(digest::sha256(self$data))
    },
    
    recursive_hash = function() {
      if (self$current_depth >= self$depth) {
        return(self$hash_data())
      } else {
        self$current_depth <- self$current_depth + 1
        self$data <- self$hash_data()
        return(self$recursive_hash())
      }
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    rounds = NULL,
    current_round = 0,
    
    initialize = function(key, rounds) {
      self$key <- key
      self$rounds <- rounds
    },
    
    simple_cipher = function(data) {
      return(paste0(replicate(nchar(data), {
        char <- substr(data, seq_along(data), seq_along(data))
        key_char <- substr(self$key, seq_along(char), seq_along(char))
        new_char <- as.character((charToRaw(char) + charToRaw(key_char)) %% 256)
        intToRaw(new_char)
      }), collapse = ""))
    },
    
    recursive_cipher = function(data) {
      if (self$current_round >= self$rounds) {
        return(data)
      } else {
        self$current_round <- self$current_round + 1
        data <- self$simple_cipher(data)
        return(self$recursive_cipher(data))
      }
    }
  )
)

main <- function() {
  initial_data <- 'SecureData'
  hash_depth <- 5
  cipher_rounds <- 3
  key <- 'Secret'
  
  hash_simulator <- HashSimulator$new(initial_data, hash_depth)
  hashed_data <- hash_simulator$recursive_hash()
  
  cipher_simulator <- CipherSimulator$new(key, cipher_rounds)
  encrypted_data <- cipher_simulator$recursive_cipher(hashed_data)
  
  print(encrypted_data)
}

main()