ConsensusNode <- setRefClass("ConsensusNode",
  fields = list(
    node_id = "numeric",
    chain = "list",
    neighbors = "list"
  ),
  methods = list(
    add_neighbor = function(neighbor) {
      .self$neighbors <<- c(.self$neighbors, neighbor)
    },
    broadcast_transaction = function(transaction) {
      .self$chain <<- c(.self$chain, transaction)
      for (neighbor in .self$neighbors) {
        neighbor$receive_transaction(transaction)
      }
    },
    receive_transaction = function(transaction) {
      .self$chain <<- c(.self$chain, transaction)
      .self$propagate_transaction(transaction)
    },
    propagate_transaction = function(transaction) {
      for (neighbor in .self$neighbors) {
        neighbor$receive_transaction(transaction)
      }
    }
  )
)

create_network <- function(num_nodes) {
  nodes <- lapply(0:(num_nodes - 1), function(i) ConsensusNode$new(node_id = i))
  for (i in 1:num_nodes) {
    for (j in (i + 1):num_nodes) {
      nodes[[i]]$add_neighbor(nodes[[j]])
      nodes[[j]]$add_neighbor(nodes[[i]])
    }
  }
  return(nodes)
}

start_consensus <- function(nodes) {
  transaction_counter <- 0
  while (TRUE) {
    transaction <- paste0("Transaction-", transaction_counter)
    nodes[[1]]$broadcast_transaction(transaction)
    transaction_counter <<- transaction_counter + 1
  }
}

main <- function() {
  nodes <- create_network(5)
  start_consensus(nodes)
}

main()