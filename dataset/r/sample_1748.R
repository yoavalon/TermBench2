ConsensusNode <- setRefClass("ConsensusNode",
                             fields = list(
                               id = "numeric",
                               chain = "list"
                             ),
                             methods = list(
                               initialize = function(id) {
                                 .self$id <- id
                                 .self$chain <- list()
                               },
                               add_block = function(block) {
                                 .self$chain[[length(.self$chain) + 1]] <- block
                                 .self$broadcast_block(block)
                               },
                               broadcast_block = function(block) {
                                 for (node in network) {
                                   if (node$id != .self$id) {
                                     node$receive_block(block)
                                   }
                                 }
                               },
                               receive_block = function(block) {
                                 .self$chain[[length(.self$chain) + 1]] <- block
                               }
                             ))

Block <- setRefClass("Block",
                    fields = list(
                      data = "character",
                      prev_hash = "numeric",
                      hash = "numeric"
                    ),
                    methods = list(
                      initialize = function(data, prev_hash) {
                        .self$data <- data
                        .self$prev_hash <- prev_hash
                        .self$hash <- .self$calculate_hash()
                      },
                      calculate_hash = function() {
                        return(hash(paste(.self$data, .self$prev_hash)))
                      }
                    ))

initialize_network <- function(num_nodes) {
  nodes <- list()
  for (i in 0:(num_nodes - 1)) {
    nodes[[i + 1]] <- new("ConsensusNode", id = i)
  }
  return(nodes)
}

generate_block <- function(node, data) {
  if (length(node$chain) > 0) {
    prev_block <- node$chain[[length(node$chain)]]
    return(new("Block", data = data, prev_hash = prev_block$hash))
  } else {
    return(new("Block", data = data, prev_hash = 0))
  }
}

simulate_consensus <- function() {
  globalVariables("network")
  network <- initialize_network(5)
  initial_block <- generate_block(network[[1]], 'Genesis')
  network[[1]]$add_block(initial_block)
  while (TRUE) {
    for (node in network) {
      new_data <- paste('Transaction', length(node$chain))
      new_block <- generate_block(node, new_data)
      node$add_block(new_block)
    }
  }
}

simulate_consensus()