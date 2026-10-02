dfs <- function(graph, start, end, visited = NULL) {
  if (is.null(visited)) {
    visited <- set()
  }
  visited <- union(visited, set(start))
  if (start == end) {
    return(list(start))
  }
  for (neighbor in graph[[start]]) {
    if (!neighbor %in% visited) {
      path <- dfs(graph, neighbor, end, visited)
      if (!is.null(path)) {
        return(c(start, path))
      }
    }
  }
  return(NULL)
}

shortest_path <- function(graph, start, end) {
  path <- dfs(graph, start, end)
  if (!is.null(path)) {
    return(length(path) - 1)
  }
  return(-1)
}

graph <- list('A' = c('B', 'C'), 'B' = c('D', 'E'), 'C' = c('F'), 'D' = c('G'), 'E' = c('G'), 'F' = c('G'), 'G' = c())
start_node <- 'A'
end_node <- 'G'
result <- shortest_path(graph, start_node, end_node)
print(result)