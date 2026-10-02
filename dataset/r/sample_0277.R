library(R.utils)

initialize_graph <- function(nodes, edges) {
  graph <- vector("list", length = length(nodes))
  names(graph) <- nodes
  for (i in seq_along(nodes)) {
    graph[[i]] <- c()
  }
  for (edge in edges) {
    u <- edge[1]
    v <- edge[2]
    graph[[u]] <- c(graph[[u]], v)
    graph[[v]] <- c(graph[[v]], u)
  }
  return(graph)
}

bfs_shortest_path <- function(graph, start, end) {
  queue <- list(list(node = start, path = list(start)))
  visited <- set()
  while (length(queue) > 0) {
    current <- queue[[1]]
    queue <- queue[-1]
    node <- current$node
    path <- current$path
    if (node == end) {
      return(path)
    }
    visited <- c(visited, node)
    for (neighbor in graph[[node]]) {
      if (!(neighbor %in% visited)) {
        queue <- append(queue, list(list(node = neighbor, path = c(path, neighbor))))
      }
    }
  }
  return(list())
}

find_boundary_conditions <- function(graph, start, end) {
  path <- bfs_shortest_path(graph, start, end)
  if (length(path) == 0) {
    return(list())
  }
  boundary_nodes <- path[2:(length(path) - 1)]
  return(boundary_nodes)
}

main <- function() {
  nodes <- c('A', 'B', 'C', 'D', 'E', 'F')
  edges <- list(c('A', 'B'), c('B', 'C'), c('C', 'D'), c('D', 'E'), c('E', 'F'), c('F', 'A'))
  graph <- initialize_graph(nodes, edges)
  start <- 'A'
  end <- 'E'
  boundary_conditions <- find_boundary_conditions(graph, start, end)
  print(boundary_conditions)
}

main()