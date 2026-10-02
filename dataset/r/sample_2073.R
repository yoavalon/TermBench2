LedgerConsensus <- R6::R6Class("LedgerConsensus",
  public = list(
    nodes = NULL,
    precision = NULL,
    transactions = NULL,
    initialize = function(nodes, precision) {
      self$nodes <- nodes
      self$precision <- precision
      self$transactions <- list()
    },
    add_transaction = function(amount) {
      self$transactions <<- c(self$transactions, amount)
    },
    validate_transaction = function(transaction) {
      return(round(transaction, self$precision) == transaction)
    },
    consensus_round = function() {
      total <- 0
      for (transaction in self$transactions) {
        if (!self$validate_transaction(transaction)) {
          return(FALSE)
        } else {
          total <- total + transaction
        }
      }
      return(round(total, self$precision) == total)
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    submit_transaction = function(amount) {
      self$ledger$add_transaction(amount)
    }
  )
)

main <- function() {
  nodes <- 5
  precision <- 10
  ledger <- LedgerConsensus$new(nodes, precision)
  node <- Node$new(ledger)
  for (i in 1:nodes) {
    node$submit_transaction(1.0 / i)
  }
  if (ledger$consensus_round()) {
    print('Consensus reached')
  } else {
    print('Consensus failed')
  }
}

main()