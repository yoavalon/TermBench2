LedgerNode <- setRefClass("LedgerNode",
  fields = list(state = "numeric"),
  methods = list(
    update_state = function(new_state) {
      .self$state <<- new_state
    },
    get_state = function() {
      return(.self$state)
    }
  )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
  fields = list(nodes = "list"),
  methods = list(
    broadcast_state = function(node_index, new_state) {
      for (i in 1:length(.self$nodes)) {
        if (i != node_index) {
          .self$nodes[[i]]$update_state(new_state)
        }
      }
    },
    check_consensus = function() {
      first_node_state <- .self$nodes[[1]]$get_state()
      for (node in .self$nodes) {
        if (node$get_state() != first_node_state) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

simulate_network <- function(nodes_count) {
  nodes <- lapply(1:nodes_count, function(i) LedgerNode$new(state = i))
  consensus <- ConsensusMechanism$new(nodes = nodes)
  while (TRUE) {
    for (i in 1:nodes_count) {
      new_state <- i + 1
      consensus$broadcast_state(node_index = i, new_state = new_state)
      if (consensus$check_consensus()) {
        return(consensus$nodes[[1]]$get_state())
      }
    }
  }
}

main <- function() {
  nodes_count <- 5
  final_state <- simulate_network(nodes_count)
  print(final_state)
}

main()