LedgerNode <- R6::R6Class(
  "LedgerNode",
  public = list(
    data = NULL,
    next = NULL,
    initialize = function(data) {
      self$data <- data
      self$next <- NULL
    }
  )
)

LedgerConsensus <- R6::R6Class(
  "LedgerConsensus",
  public = list(
    head = NULL,
    tail = NULL,
    initialize = function() {
      self$head <- NULL
      self$tail <- NULL
    },
    add_node = function(data) {
      new_node <- LedgerNode$new(data)
      if (is.null(self$head)) {
        self$head <- new_node
        self$tail <- new_node
      } else {
        self$tail$next <- new_node
        self$tail <- new_node
      }
    },
    validate_transactions = function() {
      current <- self$head
      while (!is.null(current)) {
        if (!self$is_transaction_valid(current$data)) {
          return(FALSE)
        }
        current <- current$next
      }
      return(TRUE)
    },
    is_transaction_valid = function(transaction) {
      return(transaction > 0)
    }
  )
)

process_ledger <- function(transactions) {
  ledger <- LedgerConsensus$new()
  for (transaction in transactions) {
    ledger$add_node(transaction)
  }
  return(ledger$validate_transactions())
}

main <- function() {
  transactions <- c(1.1, 2.2, 3.3, 4.4, 5.5)
  result <- process_ledger(transactions)
  print(result)
}

main()