library(pryr)

bfs_shortest_path <- function(graph, start, goal) {
  queue <- list(c(start, list(start)))
  visited <- c()
  while (length(queue) > 0) {
    item <- queue[[1]]
    queue <- queue[-1]
    node <- item[1]
    path <- item[2]
    if (node == goal) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph[[node]]) {
        if (!neighbor %in% visited) {
          queue <- c(queue, list(c(neighbor, c(path, neighbor))))
        }
      }
    }
  }
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c('G'), E = c('F'), F = c('G'), G = c())
  start_node <- 'A'
  goal_node <- 'G'
  result <- bfs_shortest_path(graph, start_node, goal_node)
  print(result)
}

main()