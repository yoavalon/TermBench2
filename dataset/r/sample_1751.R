r
LedgerNode <- setRefClass("LedgerNode",
  fields = list(data = "numeric", next_node = "LedgerNode"),
  methods = list(
    initialize = function(data, next_node = NULL) {
      .self$data <- data
      .self$next_node <- next_node
    },
    append = function(data) {
      current <- .self
      while (!is.null(current$next_node)) {
        current <- current$next_node
      }
      current$next_node <- new("LedgerNode", data = data)
    },
    traverse = function() {
      current <- .self
      while (!is.null(current)) {
        yield(current$data)
        current <- current$next_node
      }
    }
  )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
  fields = list(nodes = "list"),
  methods = list(
    initialize = function(nodes) {
      .self$nodes <- nodes
    },
    update_nodes = function(data) {
      for (node in .self$nodes) {
        node$append(data)
      }
    }
  )
)

NetworkSimulator <- setRefClass("NetworkSimulator",
  fields = list(nodes = "list", consensus = "ConsensusMechanism"),
  methods = list(
    initialize = function(num_nodes, initial_data) {
      .self$nodes <- lapply(1:num_nodes, function(_) new("LedgerNode", data = initial_data))
      .self$consensus <- new("ConsensusMechanism", nodes = .self$nodes)
    },
    simulate = function() {
      while (TRUE) {
        new_data <- sum(sapply(.self$nodes, function(node) node$data)) / length(.self$nodes)
        .self$consensus$update_nodes(new_data)
      }
    }
  )
)

main <- function() {
  simulator <- new("NetworkSimulator", num_nodes = 5, initial_data = 10)
  simulator$simulate()
}

main()