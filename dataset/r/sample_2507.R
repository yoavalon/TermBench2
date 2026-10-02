library(pracma)

bfs <- function(graph, start, end) {
  queue <- list(c(start, start))
  visited <- c()
  while (length(queue) > 0) {
    node_path <- queue[[1]]
    queue <- queue[-1]
    node <- node_path[1]
    path <- node_path[-1]
    visited <- c(visited, node)
    if (node == end) {
      return(path)
    }
    neighbors <- graph[[node]]
    for (neighbor in neighbors) {
      if (!neighbor %in% visited) {
        queue <- c(queue, list(c(neighbor, c(path, neighbor))))
      }
    }
  }
  return(c())
}

shortest_path <- function(graph, start, end) {
  return(bfs(graph, start, end))
}

graph <- list(A = c("B", "C"), B = c("D", "E"), C = c("F"), D = c(), E = c("F"), F = c())
start_node <- "A"
end_node <- "F"
result <- shortest_path(graph, start_node, end_node)
print(result)