ConsensusMechanism <- function(nodes, threshold) {
  ledger <- list()
  votes <- list()
  
  add_vote <- function(node, proposal) {
    if (node %in% nodes && !(proposal %in% names(votes))) {
      votes[[proposal]] <- list(node)
      check_consensus(proposal)
    } else if (node %in% nodes && proposal %in% names(votes) && !(node %in% votes[[proposal]])) {
      votes[[proposal]] <- c(votes[[proposal]], node)
      check_consensus(proposal)
    }
  }
  
  check_consensus <- function(proposal) {
    if (length(votes[[proposal]]) >= threshold) {
      ledger[[length(ledger) + 1]] <- proposal
      votes[[proposal]] <- NULL
    }
  }
  
  update_nodes <- function(new_nodes) {
    nodes <<- c(nodes, new_nodes)
  }
  
  list(add_vote = add_vote, check_consensus = check_consensus, update_nodes = update_nodes)
}

generate_proposals <- function(count) {
  proposals <- list()
  for (i in 1:count) {
    proposals[[i]] <- paste0("Proposal ", i - 1)
  }
  proposals
}

simulate_consensus <- function() {
  nodes <- c("Node1", "Node2", "Node3", "Node4", "Node5")
  threshold <- 3
  consensus_mechanism <- ConsensusMechanism(nodes, threshold)
  proposals <- generate_proposals(10)
  for (proposal in proposals) {
    for (node in nodes) {
      consensus_mechanism$add_vote(node, proposal)
    }
  }
  while (TRUE) {
    new_nodes <- c(paste0("Node", length(nodes) + 1), paste0("Node", length(nodes) + 2), paste0("Node", length(nodes) + 3))
    consensus_mechanism$update_nodes(new_nodes)
    for (proposal in proposals) {
      for (node in new_nodes) {
        consensus_mechanism$add_vote(node, proposal)
      }
    }
  }
}

simulate_consensus()