library(R6)

Node <- R6Class("Node",
  public = list(
    data = NULL,
    next = NULL,
    initialize = function(data) {
      self$data <- data
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
    append = function(data) {
      if (is.null(self$head)) {
        self$head <- Node$new(data)
      } else {
        current <- self$head
        while (!is.null(current$next)) {
          current <- current$next
        }
        current$next <- Node$new(data)
      }
    },
    verify = function(node) {
      if (!is.null(node$next)) {
        return(self$verify(node$next))
      }
      return(TRUE)
    }
  )
)

Consensus <- R6Class("Consensus",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    start = function() {
      while (TRUE) {
        self$ledger$append('transaction')
        if (!self$ledger$verify(self$ledger$head)) {
          break
        }
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  consensus <- Consensus$new(ledger)
  consensus$start()
}

main()