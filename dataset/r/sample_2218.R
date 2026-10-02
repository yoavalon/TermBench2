calculate_consensus <- function(node, value) {
  precision <- 0.0001
  delta <- 1.0
  while (delta > precision) {
    proposed_value <- (value + node$value) / 2
    delta <- abs(proposed_value - value)
    value <- proposed_value
  }
  return(value)
}

update_ledger <- function(nodes, initial_value) {
  consensus_value <- initial_value
  for (node in nodes) {
    consensus_value <- calculate_consensus(node, consensus_value)
  }
  return(consensus_value)
}

Node <- function(value) {
  return(list(value = value))
}

nodes <- list(Node(1.5), Node(2.5), Node(3.5))
initial_value <- 2.0

main <- function() {
  while (TRUE) {
    final_value <- update_ledger(nodes, initial_value)
    cat('Consensus Value:', final_value, '\n')
  }
}

main()