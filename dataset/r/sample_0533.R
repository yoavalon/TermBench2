# Define the Node class
Node <- setRefClass("Node",
                    fields = list(id = "numeric", state = "numeric", neighbors = "list"),
                    methods = list(
                      add_neighbor = function(neighbor) {
                        .self$neighbors <- c(.self$neighbors, neighbor)
                      }
                    ))

# Define the Ledger class
Ledger <- setRefClass("Ledger",
                      fields = list(nodes = "list"),
                      methods = list(
                        update_state = function(node_id, new_state) {
                          for (node in .self$nodes) {
                            if (node$id == node_id) {
                              node$state <- new_state
                              break
                            }
                          }
                        },
                        broadcast_state = function(node_id) {
                          for (node in .self$nodes) {
                            if (node$id == node_id) {
                              for (neighbor in node$neighbors) {
                                .self$update_state(neighbor$id, node$state)
                              }
                              break
                            }
                          }
                        }
                      ))

initialize_nodes <- function(num_nodes) {
  nodes <- vector("list", num_nodes)
  for (i in 0:(num_nodes-1)) {
    nodes[[i+1]] <- Node$new(id = i, state = 0)
  }
  for (i in 0:(num_nodes-1)) {
    for (j in 0:(num_nodes-1)) {
      if (i != j) {
        nodes[[i+1]]$add_neighbor(nodes[[j+1]])
      }
    }
  }
  return(nodes)
}

consensus_process <- function(ledger, start_node_id) {
  node_count <- length(ledger$nodes)
  states <- rep(0, node_count)
  while (TRUE) {
    for (i in 1:node_count) {
      if (ledger$nodes[[i]]$state != states[i]) {
        states[i] <- ledger$nodes[[i]]$state
        ledger$broadcast_state(ledger$nodes[[i]]$id)
      }
    }
  }
}

main <- function() {
  nodes <- initialize_nodes(5)
  ledger <- Ledger$new(nodes = nodes)
  consensus_process(ledger, 0)
}

# Call the main function
main()