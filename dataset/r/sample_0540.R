LedgerNode <- R6::R6Class("LedgerNode",
  public = list(
    data = NULL,
    next = NULL,
    initialize = function(data) {
      self$data <- data
      self$next <- NULL
    }
  )
)

DecentralizedLedger <- R6::R6Class("DecentralizedLedger",
  public = list(
    head = NULL,
    tail = NULL,
    initialize = function() {
      self$head <- NULL
      self$tail <- NULL
    },
    append = function(data) {
      new_node <- LedgerNode$new(data)
      if (is.null(self$head)) {
        self$head <- new_node
        self$tail <- new_node
      } else {
        self$tail$next <- new_node
        self$tail <- new_node
      }
    },
    consensus = function() {
      current <- self$head
      while (!is.null(current)) {
        if (current$data %% 2 == 0) {
          current$data <- current$data + 1
        } else {
          current$data <- current$data - 1
        }
        current <- current$next
      }
    }
  )
)

simulate_ledger <- function() {
  ledger <- DecentralizedLedger$new()
  for (i in 1:100) {
    ledger$append(i)
  }
  while (TRUE) {
    ledger$consensus()
  }
}

simulate_ledger()