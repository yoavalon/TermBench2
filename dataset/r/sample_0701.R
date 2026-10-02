dfs <- function(graph, node, visited, path, paths) {
  visited <- union(visited, node)
  path <- c(path, node)
  if (length(graph[[node]]) == 0) {
    paths[[length(paths) + 1]] <- path
  }
  for (neighbor in graph[[node]]) {
    if (!(neighbor %in% visited)) {
      dfs(graph, neighbor, visited, path, paths)
    }
  }
  path <- path[-length(path)]
  visited <- setdiff(visited, node)
}

shortest_path <- function(graph, start, end) {
  paths <- list()
  dfs(graph, start, character(0), character(0), paths)
  min_length <- Inf
  best_path <- NULL
  for (path in paths) {
    if (path[length(path)] == end && length(path) < min_length) {
      min_length <- length(path)
      best_path <- path
    }
  }
  return(best_path)
}

graph <- list(A = c('B', 'C'), B = c('D'), C = c('D'), D = character(0))
start_node <- 'A'
end_node <- 'D'
print(shortest_path(graph, start_node, end_node))