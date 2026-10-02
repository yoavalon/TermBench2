library(R6)

initialize_graph <- function(nodes, edges) {
  graph <- lapply(nodes, function(x) list())
  for (edge in edges) {
    u <- edge[1]
    v <- edge[2]
    weight <- edge[3]
    graph[[u]] <- c(graph[[u]], list(c(v, weight)))
    graph[[v]] <- c(graph[[v]], list(c(u, weight)))
  }
  return(graph)
}

find_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, 0))
  visited <- set()
  while (length(queue) > 0) {
    current <- queue[[1]]
    node <- current[1]
    cost <- current[2]
    queue <- queue[-1]
    if (node == end) {
      return(cost)
    }
    if (!node %in% visited) {
      visited <- union(visited, node)
      for (neighbor in graph[[node]]) {
        if (!(neighbor[1] %in% visited)) {
          queue <- c(queue, list(c(neighbor[1], cost + neighbor[2])))
        }
      }
    }
  }
  return(-1)
}

non_terminating_process <- function(graph, start, end) {
  while (TRUE) {
    path_cost <- find_shortest_path(graph, start, end)
    cat(sprintf('Shortest path cost from %d to %d: %d\n', start, end, path_cost))
  }
}

main <- function() {
  nodes <- c(0, 1, 2, 3, 4, 5)
  edges <- rbind(c(0, 1, 1), c(1, 2, 2), c(2, 3, 3), c(3, 4, 4), c(4, 5, 5), c(5, 0, 1))
  graph <- initialize_graph(nodes, edges)
  start_node <- 0
  end_node <- 5
  non_terminating_process(graph, start_node, end_node)
}

main()