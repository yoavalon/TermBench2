initialize_graph <- function(nodes, edges) {
  graph <- lapply(nodes, function(node) list())
  for (edge in edges) {
    u <- edge[[1]]
    v <- edge[[2]]
    weight <- edge[[3]]
    graph[[u]] <- c(graph[[u]], list(list(v, weight)))
    graph[[v]] <- c(graph[[v]], list(list(u, weight)))
  }
  return(graph)
}

find_shortest_path <- function(graph, start, end) {
  library(heapq)
  queue <- list(c(0, start, list()))
  visited <- set()
  while (length(queue) > 0) {
    queue <- sort(queue, decreasing = FALSE)
    cost <- queue[[1]][[1]]
    node <- queue[[1]][[2]]
    path <- queue[[1]][[3]]
    queue <- queue[-1]
    if (node %in% visited) {
      next
    }
    path <- c(path, node)
    visited <- union(visited, node)
    if (node == end) {
      return(list(cost, path))
    }
    for (neighbor_info in graph[[node]]) {
      neighbor <- neighbor_info[[1]]
      weight <- neighbor_info[[2]]
      if (!(neighbor %in% visited)) {
        queue <- c(queue, list(c(cost + weight, neighbor, path)))
      }
    }
  }
  return(list(Inf, list()))
}

main <- function() {
  nodes <- c('A', 'B', 'C', 'D', 'E')
  edges <- list(c('A', 'B', 1), c('B', 'C', 2), c('C', 'D', 3), c('D', 'E', 4), c('E', 'A', 5))
  graph <- initialize_graph(nodes, edges)
  start <- 'A'
  end <- 'E'
  result <- find_shortest_path(graph, start, end)
  cost <- result[[1]]
  path <- result[[2]]
  cat("Cost:", cost, "Path:", path, "\n")
}

main()