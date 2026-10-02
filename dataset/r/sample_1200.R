Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    next_node = NULL,
    initialize = function(value, next_node = NULL) {
      self$value <- value
      self$next_node <- next_node
    },
    append = function(value) {
      if (is.null(self$next_node)) {
        self$next_node <- Node$new(value)
      } else {
        self$next_node$append(value)
      }
    },
    traverse = function() {
      current <- self
      while (!is.null(current)) {
        yield(current$value)
        current <- current$next_node
      }
    }
  )
)

Ledger <- R6::R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    add_block = function(block) {
      if (is.null(self$head)) {
        self$head <- Node$new(block)
      } else {
        self$head$append(block)
      }
    },
    consensus = function() {
      if (is.null(self$head)) {
        return()
      }
      for (value in self$head$traverse()) {
        if (value < 0) {
          self$add_block(value + 1)
        } else {
          self$add_block(value - 1)
        }
      }
      self$consensus()
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  ledger$add_block(10)
  ledger$add_block(-5)
  ledger$add_block(3)
  ledger$consensus()
}

main()