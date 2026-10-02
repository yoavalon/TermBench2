library(R6)

ConsensusNode <- R6::R6Class("ConsensusNode",
  public = list(
    state = NULL,
    neighbors = NULL,
    initialize = function(state) {
      self$state <- state
      self$neighbors <- list()
    },
    add_neighbor = function(node) {
      self$neighbors <- c(self$neighbors, node)
    },
    update_state = function() {
      new_state <- self$state
      for (neighbor in self$neighbors) {
        new_state <- new_state + neighbor$state
      }
      self$state <- new_state %% 100
    }
  )
)

Ledger <- R6::R6Class("Ledger",
  public = list(
    nodes = NULL,
    transactions = NULL,
    initialize = function() {
      self$nodes <- list()
      self$transactions <- list()
    },
    add_node = function(node) {
      self$nodes <- c(self$nodes, node)
    },
    add_transaction = function(transaction) {
      self$transactions <- c(self$transactions, transaction)
    },
    process_transactions = function() {
      for (transaction in self$transactions) {
        for (node in self$nodes) {
          node$state <- (node$state + transaction) %% 100
        }
      }
      self$transactions <- list()
    }
  )
)

ConsensusMechanism <- R6::R6Class("ConsensusMechanism",
  public = list(
    ledger = NULL,
    initialize = function(ledger) {
      self$ledger <- ledger
    },
    run = function() {
      while (TRUE) {
        self$ledger$process_transactions()
        for (node in self$ledger$nodes) {
          node$update_state()
        }
      }
    }
  )
)

main <- function() {
  ledger <- Ledger$new()
  node1 <- ConsensusNode$new(10)
  node2 <- ConsensusNode$new(20)
  node3 <- ConsensusNode$new(30)
  node1$add_neighbor(node2)
  node1$add_neighbor(node3)
  node2$add_neighbor(node1)
  node2$add_neighbor(node3)
  node3$add_neighbor(node1)
  node3$add_neighbor(node2)
  ledger$add_node(node1)
  ledger$add_node(node2)
  ledger$add_node(node3)
  mechanism <- ConsensusMechanism$new(ledger)
  ledger$add_transaction(5)
  mechanism$run()
}

main()