HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    data = NULL,
    result = NULL,
    initialize = function(data) {
      self$data <- data
      self$result <- NULL
    },
    compute_hash = function() {
      if (length(self$data) == 0) {
        self$result <- 0
      } else {
        self$result <- self$_hash_recursive(self$data, 1)
      }
    },
    _hash_recursive = function(data, index) {
      if (index > length(data)) {
        return(0)
      } else {
        return((data[index] + self$_hash_recursive(data, index + 1)) %% 1000000007)
      }
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    key = NULL,
    data = NULL,
    result = NULL,
    initialize = function(key, data) {
      self$key <- key
      self$data <- data
      self$result <- NULL
    },
    encrypt = function() {
      if (length(self$data) == 0) {
        self$result <- c()
      } else {
        self$result <- self$_encrypt_recursive(self$data, 1)
      }
    },
    _encrypt_recursive = function(data, index) {
      if (index > length(data)) {
        return(c())
      } else {
        return(c((data[index] + self$key) %% 256, self$_encrypt_recursive(data, index + 1)))
      }
    }
  )
)

main <- function() {
  data <- charToRaw('Hello, World!')
  hash_sim <- HashSimulator$new(data)
  hash_sim$compute_hash()
  print(paste('Hash:', hash_sim$result))
  key <- 42
  cipher_sim <- CipherSimulator$new(key, data)
  cipher_sim$encrypt()
  print(paste('Encrypted:', paste(cipher_sim$result, collapse = ' ')))
}

main()