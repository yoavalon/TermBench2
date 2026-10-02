bfs <- function(graph, start, end, visited = NULL) {
  if (is.null(visited)) {
    visited <- c()
  }
  visited <- c(visited, start)
  if (start == end) {
    return(c(start))
  }
  for (neighbor in graph[[start]]) {
    if (!(neighbor %in% visited)) {
      path <- bfs(graph, neighbor, end, visited)
      if (length(path) > 0) {
        return(c(start, path))
      }
    }
  }
  return(c())
}

graph <- list(A = c("B", "C"), B = c("D", "E"), C = c("F"), D = c(), E = c("F"), F = c())
bfs(graph, "A", "F")