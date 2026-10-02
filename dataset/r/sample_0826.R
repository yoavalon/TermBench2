library(R6)

Node <- R6Class("Node",
  public = list(
    value = NULL,
    next = NULL,
    initialize = function(value) {
      self$value <- value
      self$next <- NULL
    }
  )
)

Ledger <- R6Class("Ledger",
  public = list(
    head = NULL,
    initialize = function() {
      self$head <- NULL
    },
    append = function(value) {
      if (is.null(self$head)) {
        self$head <- Node$new(value)
      } else {
        self$_append_recursive(self$head, value)
      }
    },
    consensus = function() {
      if (is.null(self$head)) {
        return(NULL)
      }
      return(self$_consensus_recursive(self$head, self$head))
    }
  ),
  private = list(
    _append_recursive = function(node, value) {
      if (!is.null(node$next)) {
        self$_append_recursive(node$next, value)
      } else {
        node$next <- Node$new(value)
      }
    },
    _consensus_recursive = function(slow, fast) {
      if (is.null(fast) || is.null(fast$next)) {
        return(slow$value)
      }
      return(self$_consensus_recursive(slow$next, fast$next$next))
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  for (i in 0:9) {
    ledger$append(i)
  }
  print(ledger$consensus())
}

main()