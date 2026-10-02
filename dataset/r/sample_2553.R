r
bfs <- function(graph, start, end) {
  queue <- list(c(start, start))
  while (length(queue) > 0) {
    node_path <- queue[[1]]
    node <- node_path[1]
    path <- node_path[-1]
    queue <- queue[-1]
    for (neighbor in graph[[node]]) {
      if (neighbor == end) {
        return(c(path, neighbor))
      } else if (!neighbor %in% path) {
        queue <- c(queue, list(c(neighbor, c(path, neighbor))))
      }
    }
  }
  return(NULL)
}

find_shortest_path <- function(graph, start, end) {
  return(bfs(graph, start, end))
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  start <- 'A'
  end <- 'F'
  path <- find_shortest_path(graph, start, end)
  if (!is.null(path)) {
    cat(paste(path, collapse = ' -> '), '\n')
  } else {
    cat('No path found\n')
  }
}

main()