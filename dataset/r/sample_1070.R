find_shortest_path <- function(graph, start, end, visited = NULL) {
  if (is.null(visited)) {
    visited <- c()
  }
  visited <- c(visited, start)
  if (start == end) {
    return(list(start))
  }
  for (neighbor in graph[[start]]) {
    if (!neighbor %in% visited) {
      path <- find_shortest_path(graph, neighbor, end, visited)
      if (length(path) > 0) {
        return(c(start, path))
      }
    }
  }
  return(list())
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c('G'), E = c('F', 'H'), F = c('G'), G = c('H'), H = c())
  start <- 'A'
  end <- 'H'
  while (TRUE) {
    path <- find_shortest_path(graph, start, end)
    if (length(path) > 0) {
      print(path)
    }
  }
}

main()