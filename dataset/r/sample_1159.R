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
      return(c(self$value, if (!is.null(self$next_node)) self$next_node$traverse() else NULL))
    }
  )
)

Ledger <- R6::R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    add_transaction = function(transaction) {
      if (is.null(self$head)) {
        self$head <- Node$new(transaction)
      } else {
        self$head$append(transaction)
      }
    },
    verify_consensus = function() {
      if (!is.null(self$head)) {
        return(c(self$head$traverse(), self$verify_consensus()))
      } else {
        return(NULL)
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  for (i in 1:1000000) {
    ledger$add_transaction(paste("Transaction", i))
  }
  for (transaction in ledger$verify_consensus()) {
    print(transaction)
  }
}

main()