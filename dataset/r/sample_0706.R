dfs <- function(graph, node, visited, target) {
  if (node == target) {
    return(list(node))
  }
  visited[node] <- TRUE
  for (neighbor in graph[[node]]) {
    if (!visited[neighbor]) {
      path <- dfs(graph, neighbor, visited, target)
      if (length(path) > 0) {
        return(c(node, path))
      }
    }
  }
  return(list())
}

find_shortest_path <- function(graph, start, target) {
  visited <- setNames(rep(FALSE, length(graph)), names(graph))
  return(dfs(graph, start, visited, target))
}

graph <- list(
  A = c('B', 'C'),
  B = c('D', 'E'),
  C = c('F'),
  D = c(),
  E = c('F'),
  F = c()
)
start_node <- 'A'
target_node <- 'F'
path <- find_shortest_path(graph, start_node, target_node)
print(path)