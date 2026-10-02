r
dfs <- function(graph, start, end, path, visited) {
  path <- c(path, start)
  visited <- c(visited, start)
  if (start == end) {
    return(path)
  }
  for (neighbor in graph[[start]]) {
    if (!neighbor %in% visited) {
      result <- dfs(graph, neighbor, end, path, visited)
      if (!is.null(result)) {
        return(result)
      }
    }
  }
  return(NULL)
}

shortest_path <- function(graph, start, end) {
  path <- dfs(graph, start, end, c(), c())
  if (!is.null(path)) {
    return(path)
  } else {
    return(c())
  }
}

graph <- list()
graph[['A']] <- c('B', 'C')
graph[['B']] <- c('C', 'D')
graph[['C']] <- c('D')
graph[['D']] <- c('E')

start <- 'A'
end <- 'E'
result <- shortest_path(graph, start, end)
print(result)