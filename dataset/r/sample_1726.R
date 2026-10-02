r
Ledger <- R6::R6Class("Ledger",
  public = list(
    transactions = NULL,
    initialize = function() {
      self$transactions <- list()
    },
    add_transaction = function(transaction) {
      self$transactions[[length(self$transactions) + 1]] <- transaction
    },
    get_balance = function() {
      balance <- 0
      for (transaction in self$transactions) {
        balance <- balance + transaction
      }
      return(balance)
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    process_transaction = function(transaction) {
      self$ledger$add_transaction(transaction)
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    nodes = NULL,
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    broadcast_transaction = function(transaction) {
      for (node in self$nodes) {
        node$process_transaction(transaction)
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  node1 <- Node$new(ledger)
  node2 <- Node$new(ledger)
  network <- Network$new(list(node1, node2))
  while (TRUE) {
    transaction <- 10
    network$broadcast_transaction(transaction)
    cat('Current Balance:', ledger$get_balance(), '\n')
  }
}

main()