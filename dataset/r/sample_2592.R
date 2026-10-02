library(pryr)

bfs_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, start))
  visited <- set()
  while (!is_empty(queue)) {
    item <- queue[[1]]
    queue <- queue[-1]
    node <- item[1]
    path <- item[2]
    if (node == end) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- union(visited, node)
      neighbors <- graph[[node]]
      for (neighbor in neighbors) {
        if (!neighbor %in% visited) {
          queue <- c(queue, list(c(neighbor, c(path, neighbor))))
        }
      }
    }
  }
  return(NULL)
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  start <- 'A'
  end <- 'F'
  path <- bfs_shortest_path(graph, start, end)
  if (!is.null(path)) {
    cat(paste(path, collapse = ' -> '), "\n")
  } else {
    cat('No path found\n')
  }
}

main()