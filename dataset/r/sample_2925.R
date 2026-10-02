SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    value = NULL,
    initialize = function(initial_value) {
      self$value <- initial_value
    },
    generate = function() {
      repeat {
        yield <- self$value
        self$value <- self$next_value()
        yield
      }
    },
    next_value = function() {
      a <- 0
      b <- 1
      repeat {
        yield <- b
        a <- b
        b <- a + b
        yield
      }
    }
  )
)

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
  public = list(
    sequence = NULL,
    current_value = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
      self$current_value <- sequence$generate()
    },
    validate = function() {
      repeat {
        if (self$current_value %% 2 == 0) {
          self$current_value <- sequence$generate()
        } else {
          return(self$current_value)
        }
      }
    }
  )
)

Ledger <- R6::R6Class("Ledger",
  public = list(
    consensus = NULL,
    entries = NULL,
    initialize = function(consensus) {
      self$consensus <- consensus
      self$entries <- c()
    },
    record = function() {
      repeat {
        entry <- consensus$validate()
        self$entries <- c(self$entries, entry)
        cat("Recorded entry:", entry, "\n")
      }
    }
  )
)

main <- function() {
  sequence <- SequenceGenerator$new(0)
  consensus <- ConsensusMechanism$new(sequence)
  ledger <- Ledger$new(consensus)
  ledger$record()
}

main()