SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    start = NULL,
    stop = NULL,
    initialize = function(start, stop) {
      self$start <- start
      self$stop <- stop
    },
    generate_sequence = function() {
      sequence <- c()
      current <- self$start
      while (current <= self$stop) {
        sequence <- c(sequence, current)
        current <- current + 1
      }
      return(sequence)
    }
  )
)

SemanticValidator <- R6::R6Class("SemanticValidator",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    validate = function() {
      valid <- TRUE
      for (i in 1:(length(self$sequence) - 1)) {
        if (self$sequence[i] + 1 != self$sequence[i + 1]) {
          valid <- FALSE
          break
        }
      }
      return(valid)
    }
  )
)

ResultFormatter <- R6::R6Class("ResultFormatter",
  public = list(
    sequence = NULL,
    is_valid = NULL,
    initialize = function(sequence, is_valid) {
      self$sequence <- sequence
      self$is_valid <- is_valid
    },
    format = function() {
      status <- ifelse(self$is_valid, 'valid', 'invalid')
      return(paste("Sequence:", self$sequence, "- Status:", status))
    }
  )
)

main <- function() {
  start <- 1
  stop <- 10
  generator <- SequenceGenerator$new(start, stop)
  sequence <- generator$generate_sequence()
  validator <- SemanticValidator$new(sequence)
  is_valid <- validator$validate()
  formatter <- ResultFormatter$new(sequence, is_valid)
  cat(formatter$format(), "\n")
}

main()