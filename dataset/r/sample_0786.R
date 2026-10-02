find_path <- function(graph, start, end, path = NULL) {
  if (is.null(path)) {
    path <- c()
  }
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  if (!(start %in% names(graph))) {
    return(NULL)
  }
  for (node in graph[[start]]) {
    if (!(node %in% path)) {
      newpath <- find_path(graph, node, end, path)
      if (!is.null(newpath)) {
        return(newpath)
      }
    }
  }
  return(NULL)
}

shortest_path <- function(graph, start, end) {
  path <- find_path(graph, start, end)
  if (!is.null(path)) {
    return(length(path) - 1)
  } else {
    return(Inf)
  }
}

g <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
print(shortest_path(g, 'A', 'F'))