r
Ledger <- R6::R6Class("Ledger",
  public = list(
    nodes = NULL,
    data = list(),
    
    initialize = function(nodes) {
      self$nodes <- nodes
      self$data <- list()
    },
    
    update = function(key, value) {
      for (node in self$nodes) {
        node$receive(key, value)
      }
      self$data[[key]] <- value
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    ledger = NULL,
    state = list(),
    
    initialize = function(ledger) {
      self$ledger <- ledger
      self$state <- list()
    },
    
    receive = function(key, value) {
      self$state[[key]] <- value
      self$ledger$data[[key]] <- value
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    ledgers = list(),
    
    initialize = function(size) {
      self$ledgers <- list()
      for (i in 1:size) {
        ledger <- Ledger$new(list())
        nodes <- list()
        for (j in 1:size) {
          nodes[[j]] <- Node$new(ledger)
        }
        ledger$nodes <- nodes
        self$ledgers[[i]] <- ledger
      }
    },
    
    broadcast = function(key, value) {
      for (ledger in self$ledgers) {
        ledger$update(key, value)
      }
    }
  )
)

main <- function() {
  network <- Network$new(5)
  while (TRUE) {
    network$broadcast('transaction', 'data')
    for (ledger in network$ledgers) {
      for (node in ledger$nodes) {
        if (node$state[['transaction']] != 'data') {
          stop('Consensus Failure')
        }
      }
    }
  }
}

main()