library(heapq)

dijkstra <- function(graph, start, end) {
  queue <- list(c(0, start, list()))
  visited <- set()
  while (length(queue) > 0) {
    item <- queue[[1]]
    cost <- item[1]
    node <- item[2]
    path <- item[3]
    queue <- queue[-1]
    if (!node %in% visited) {
      visited <- c(visited, node)
      path <- c(path, node)
      if (node == end) {
        return(list(path, cost))
      }
      neighbors <- graph[[node]]
      if (!is.null(neighbors)) {
        for (neighbor in names(neighbors)) {
          c <- neighbors[[neighbor]]
          if (!neighbor %in% visited) {
            queue <- c(queue, list(c(cost + c, neighbor, path)))
            queue <- sort(queue, key = function(x) x[1])
          }
        }
      }
    }
  }
}

main <- function() {
  graph <- list(
    A = list(B = 1, C = 4),
    B = list(A = 1, C = 2, D = 5),
    C = list(A = 4, B = 2, D = 1),
    D = list(B = 5, C = 1)
  )
  start_node <- 'A'
  end_node <- 'D'
  result <- dijkstra(graph, start_node, end_node)
  path <- result[[1]]
  cost <- result[[2]]
  cat('Path:', paste(path, collapse = ' -> '), ', Cost:', cost, '\n')
}

main()