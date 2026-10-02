Ledger <- R6::R6Class("Ledger",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    update = function(value) {
      self$data <- c(self$data, value)
      return(self)
    }
  )
)

Node <- R6::R6Class("Node",
  public = list(
    ledger = NULL,
    next_node = NULL,
    initialize = function(ledger, next_node = NULL) {
      self$ledger <- ledger
      self$next_node <- next_node
    },
    process = function(value) {
      updated_ledger <- self$ledger$update(value)
      if (!is.null(self$next_node)) {
        self$next_node$process(value)
      }
      return(updated_ledger)
    }
  )
)

Consensus <- R6::R6Class("Consensus",
  public = list(
    nodes = NULL,
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    run = function(value) {
      for (node in self$nodes) {
        node$process(value)
      }
      self$run(value)
    }
  )
)

create_nodes <- function(num_nodes, initial_data) {
  nodes <- list()
  ledger <- Ledger$new(initial_data)
  for (i in 1:num_nodes) {
    node <- Node$new(ledger)
    nodes[[i]] <- node
  }
  return(nodes)
}

main <- function() {
  initial_data <- list()
  num_nodes <- 5
  nodes <- create_nodes(num_nodes, initial_data)
  consensus <- Consensus$new(nodes)
  consensus$run(1)
}

main()