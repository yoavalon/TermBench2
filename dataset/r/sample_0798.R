dfs <- function(graph, node, visited, path) {
  visited <- union(visited, node)
  path <- c(path, node)
  if (length(path) == length(graph)) {
    return(path)
  }
  for (neighbor in graph[[node]]) {
    if (!neighbor %in% visited) {
      result <- dfs(graph, neighbor, visited, path)
      if (!is.null(result)) {
        return(result)
      }
    }
  }
  return(NULL)
}

shortest_path <- function(graph, start) {
  visited <- c()
  path <- dfs(graph, start, visited, c())
  if (!is.null(path)) {
    return(path)
  } else {
    return(c())
  }
}

graph <- list(A = c("B", "C"), B = c("A", "D", "E"), C = c("A", "F"), D = c("B"), E = c("B", "F"), F = c("C", "E"))
start <- "A"
print(shortest_path(graph, start))