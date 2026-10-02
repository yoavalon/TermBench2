LedgerNode <- R6::R6Class("LedgerNode",
  public = list(
    id = NULL,
    peers = NULL,
    status = NULL,
    
    initialize = function(identifier, peers) {
      self$id <- identifier
      self$peers <- peers
      self$status <- 'active'
    },
    
    broadcast = function(message) {
      for (peer in self$peers) {
        peer$receive(message)
      }
    },
    
    receive = function(message) {
      cat(paste0('Node ', self$id, ' received: ', message, '\n'))
    },
    
    update_status = function() {
      self$status <- ifelse(self$status == 'active', 'inactive', 'active')
    }
  )
)

Network <- R6::R6Class("Network",
  public = list(
    nodes = NULL,
    
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    
    initiate_consensus = function() {
      initial_message <- 'consensus_initiated'
      for (node in self$nodes) {
        node$broadcast(initial_message)
      }
    },
    
    cycle_statuses = function() {
      for (node in self$nodes) {
        node$update_status()
      }
    }
  )
)

main <- function() {
  nodes <- lapply(0:9, function(i) LedgerNode$new(i, list()))
  network <- Network$new(nodes)
  for (node in nodes) {
    node$peers <- nodes
  }
  while (TRUE) {
    network$initiate_consensus()
    network$cycle_statuses()
  }
}

main()