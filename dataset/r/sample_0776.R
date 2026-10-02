find_shortest_path <- function(graph, start, end, path = c()) {
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  if (!(start %in% names(graph))) {
    return(NULL)
  }
  shortest <- NULL
  for (node in graph[[start]]) {
    if (!(node %in% path)) {
      newpath <- find_shortest_path(graph, node, end, path)
      if (!is.null(newpath)) {
        if (is.null(shortest) || length(newpath) < length(shortest)) {
          shortest <- newpath
        }
      }
    }
  }
  return(shortest)
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('C', 'D'), C = c('D'), D = c('C'), E = c('F'), F = c('C'))
  start <- 'A'
  end <- 'D'
  print(find_shortest_path(graph, start, end))
}

main()