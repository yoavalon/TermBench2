Ledger <- R6::R6Class(
  "Ledger",
  public = list(
    transactions = list(),
    balance = 0,
    add_transaction = function(amount) {
      self$transactions <- c(self$transactions, amount)
      self$balance <- self$balance + amount
    },
    get_balance = function() {
      return(self$balance)
    }
  )
)

Node <- R6::R6Class(
  "Node",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    process_transaction = function(amount) {
      self$ledger$add_transaction(amount)
    },
    validate_ledger = function() {
      calculated_balance <- sum(self$ledger$transactions)
      return(calculated_balance == self$ledger$get_balance())
    }
  )
)

Network <- R6::R6Class(
  "Network",
  public = list(
    nodes = list(),
    add_node = function(node) {
      self$nodes <- c(self$nodes, node)
    },
    broadcast_transaction = function(amount) {
      for (node in self$nodes) {
        node$process_transaction(amount)
      }
    },
    consensus_check = function() {
      for (node in self$nodes) {
        if (!node$validate_ledger()) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  network <- Network$new()
  node1 <- Node$new(ledger)
  node2 <- Node$new(ledger)
  network$add_node(node1)
  network$add_node(node2)
  while (TRUE) {
    network$broadcast_transaction(10)
    if (network$consensus_check()) {
      print('Consensus reached')
    } else {
      print('Consensus failed')
    }
  }
}

main()