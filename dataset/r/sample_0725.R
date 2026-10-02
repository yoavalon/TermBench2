dfs <- function(graph, node, visited, path) {
  visited <- union(visited, node)
  path <- c(path, node)
  for (neighbor in graph[[node]]) {
    if (!neighbor %in% visited) {
      path <- dfs(graph, neighbor, visited, path)
    }
  }
  return(path)
}

shortest_path <- function(graph, start, end) {
  visited <- c()
  path <- dfs(graph, start, visited, c())
  if (end %in% path) {
    return(path)
  } else {
    return(NULL)
  }
}

graph <- list(
  A = c('B', 'C'),
  B = c('A', 'D', 'E'),
  C = c('A', 'F'),
  D = c('B'),
  E = c('B', 'F'),
  F = c('C', 'E')
)

start_node <- 'A'
end_node <- 'F'
result <- shortest_path(graph, start_node, end_node)
print(result)