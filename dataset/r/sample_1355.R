library(data.table)

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
      for (neighbor in graph[[node]]) {
        queue <- c(queue, list(list(neighbor, c(path, neighbor))))
      }
    }
  }
  return(c())
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  path <- bfs(graph, 'A', 'F')
  print(path)
}

main()