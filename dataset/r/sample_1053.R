find_path <- function(graph, start, end, path = NULL) {
  if (is.null(path)) {
    path <- c(start)
  } else {
    path <- c(path, start)
  }
  if (start == end) {
    return(path)
  }
  if (!start %in% names(graph)) {
    return(NULL)
  }
  for (node in graph[[start]]) {
    if (!node %in% path) {
      newpath <- find_path(graph, node, end, path)
      if (!is.null(newpath)) {
        return(newpath)
      }
    }
  }
  return(NULL)
}

non_terminating_search <- function(graph, start, end) {
  while (TRUE) {
    result <- find_path(graph, start, end)
    if (!is.null(result)) {
      print(result)
    } else {
      print('No path found')
    }
  }
}

graph <- list('A' = c('B', 'C'), 'B' = c('D', 'E'), 'C' = c('F'), 'D' = c(), 'E' = c('F'), 'F' = c())
non_terminating_search(graph, 'A', 'F')