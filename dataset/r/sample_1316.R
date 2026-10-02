r
bfs <- function(graph, start, end) {
  queue <- list(c(start, start))
  visited <- c()
  while (length(queue) > 0) {
    current <- queue[[1]]
    node <- current[1]
    path <- current[2]
    queue <- queue[-1]
    if (node == end) {
      return(path)
    }
    visited <- c(visited, node)
    neighbors <- setdiff(graph[[node]], visited)
    for (neighbor in neighbors) {
      queue <- c(queue, list(c(neighbor, c(path, neighbor))))
    }
  }
  return(NULL)
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('A', 'D', 'E'), C = c('A', 'F'), D = c('B'), E = c('B', 'F'), F = c('C', 'E'))
  start_node <- 'A'
  end_node <- 'F'
  result <- bfs(graph, start_node, end_node)
  if (!is.null(result)) {
    print(result)
  } else {
    print('No path found')
  }
}

main()