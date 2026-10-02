dfs <- function(graph, node, visited, path) {
  if (!node %in% visited) {
    visited <<- c(visited, node)
    path <<- c(path, node)
    for (neighbor in graph[[node]]) {
      dfs(graph, neighbor, visited, path)
    }
  }
  return(path)
}

shortest_path <- function(graph, start, end) {
  visited <- c()
  path <- c()
  path <- dfs(graph, start, visited, path)
  if (end %in% path) {
    return(which(path == end)[1])
  }
  return(-1)
}

graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
start_node <- 'A'
end_node <- 'F'
result <- shortest_path(graph, start_node, end_node)
print(result)