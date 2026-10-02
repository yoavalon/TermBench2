library(pryr)

bfs <- function(graph, start, end) {
  queue <- list(c(start, 0))
  visited <- set()
  while (length(queue) > 0) {
    node_dist <- queue[[1]]
    node <- node_dist[1]
    dist <- node_dist[2]
    queue <- queue[-1]
    if (node == end) {
      return(dist)
    }
    if (!node %in% visited) {
      visited <- union(visited, node)
      for (neighbor in graph[[node]]) {
        queue <- c(queue, list(c(neighbor, dist + 1)))
      }
    }
  }
  return(-1)
}

main <- function() {
  graph <- list(c(1, 2), c(2), c(0, 3), c(3))
  start <- 0
  end <- 3
  result <- bfs(graph, start, end)
  print(result)
}

main()