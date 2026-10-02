Sequence <- R6::R6Class("Sequence",
  public = list(
    n = NULL,
    initialize = function(n) {
      self$n <- n
    },
    generate = function() {
      result <- c()
      for (i in 0:(self$n - 1)) {
        result <- c(result, self$transform(i))
      }
      return(result)
    },
    transform = function(x) {
      return((x * x + 3 * x + 1) %% 101)
    }
  )
)

HashSimulator <- R6::R6Class("HashSimulator",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    hash = function() {
      total <- 0
      for (num in self$sequence) {
        total <- (total + num * 23) %% 1001
      }
      return(total)
    }
  )
)

CipherSimulator <- R6::R6Class("CipherSimulator",
  public = list(
    hash_value = NULL,
    initialize = function(hash_value) {
      self$hash_value <- hash_value
    },
    encrypt = function() {
      encrypted <- c()
      for (i in 0:(self$hash_value - 1)) {
        encrypted <- c(encrypted, (i * self$hash_value + i) %% 1009)
      }
      return(encrypted)
    }
  )
)

main <- function() {
  n <- 50
  sequence <- Sequence$new(n)$generate()
  hash_simulator <- HashSimulator$new(sequence)
  hash_value <- hash_simulator$hash()
  cipher_simulator <- CipherSimulator$new(hash_value)
  encrypted <- cipher_simulator$encrypt()
  print(encrypted)
}

main()