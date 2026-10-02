update_node_status <- function(nodes, node_id, new_status) {
  nodes[node_id] <<- new_status
  return(nodes)
}

simulate_network_activity <- function(nodes) {
  for (node_id in names(nodes)) {
    current_status <- nodes[node_id]
    if (current_status == 'inactive') {
      nodes <- update_node_status(nodes, node_id, 'active')
    } else {
      nodes <- update_node_status(nodes, node_id, 'inactive')
    }
  }
  return(nodes)
}

main <- function() {
  initial_nodes <- c(node1 = 'inactive', node2 = 'active', node3 = 'inactive')
  while (TRUE) {
    initial_nodes <- simulate_network_activity(initial_nodes)
  }
}

main()