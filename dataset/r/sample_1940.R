initialize_graph <- function(nodes, edges) {
  graph <- lapply(nodes, function(node) list())
  for (edge in edges) {
    u <- edge[1]
    v <- edge[2]
    weight <- edge[3]
    graph[[u]] <- c(graph[[u]], list(c(v, weight)))
    graph[[v]] <- c(graph[[v]], list(c(u, weight)))
  }
  return(graph)
}

dijkstra <- function(graph, start, target) {
  library(heapq)
  queue <- list(c(0, start, list()))
  visited <- set()
  while (length(queue) > 0) {
    queue <- sort(queue)
    cost <- queue[[1]][1]
    node <- queue[[1]][2]
    path <- queue[[1]][3]
    queue <- queue[-1]
    if (!node %in% visited) {
      visited <- c(visited, node)
      path <- c(path, node)
      if (node == target) {
        return(list(cost, path))
      }
      for (neighbor_weight in graph[[node]]) {
        neighbor <- neighbor_weight[1]
        weight <- neighbor_weight[2]
        if (!neighbor %in% visited) {
          queue <- c(queue, list(c(cost + weight, neighbor, path)))
        }
      }
    }
  }
  return(list(Inf, list()))
}

main <- function() {
  nodes <- c('A', 'B', 'C', 'D', 'E')
  edges <- list(c('A', 'B', 1.0), c('B', 'C', 2.5), c('C', 'D', 1.0), c('D', 'E', 1.5), c('A', 'E', 4.0))
  graph <- initialize_graph(nodes, edges)
  result <- dijkstra(graph, 'A', 'E')
  cat('Shortest path cost:', result[[1]], ', Path:', paste(result[[2]], collapse = ' '), '\n')
}

main()