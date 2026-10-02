library(dplyr)

bfs <- function(graph, start, end) {
  queue <- list(list(start, list(start)))
  visited <- c()
  while (length(queue) > 0) {
    current <- queue[[1]]
    node <- current[[1]]
    path <- current[[2]]
    queue <- queue[-1]
    if (node == end) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- c(visited, node)
      neighbors <- graph[[node]]
      for (neighbor in neighbors) {
        queue <- c(queue, list(list(neighbor, c(path, neighbor))))
      }
    }
  }
  return(NULL)
}

shortest_path <- function(graph, start, end) {
  return(bfs(graph, start, end))
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  start <- 'A'
  end <- 'F'
  path <- shortest_path(graph, start, end)
  if (!is.null(path)) {
    cat('Shortest path:', paste(path, collapse = ' '), '\n')
  } else {
    cat('No path found\n')
  }
}

main()