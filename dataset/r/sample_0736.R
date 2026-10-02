dfs <- function(graph, node, visited, path) {
  if (!node %in% visited) {
    visited <- c(visited, node)
    path <- c(path, node)
    for (neighbor in graph[[node]]) {
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
    return(c())
  }
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  start <- 'A'
  end <- 'F'
  result <- shortest_path(graph, start, end)
  print(result)
}

main()