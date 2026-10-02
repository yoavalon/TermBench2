dfs <- function(graph, start, end, path, visited) {
  path <- c(path, start)
  visited <- c(visited, start)
  if (start == end) {
    return(path)
  }
  for (neighbor in graph[[start]]) {
    if (!(neighbor %in% visited)) {
      result <- dfs(graph, neighbor, end, path, visited)
      if (!is.null(result)) {
        return(result)
      }
    }
  }
  return(NULL)
}

find_shortest_path <- function(graph, start, end) {
  dfs(graph, start, end, c(), c())
}

graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
path <- find_shortest_path(graph, 'A', 'F')
if (!is.null(path)) {
  print(paste('Path found:', paste(path, collapse = ' ')))
} else {
  print('No path found')
}