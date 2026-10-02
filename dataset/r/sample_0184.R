library(pryr)

bfs <- function(graph, start, end) {
  queue <- list(c(start, 0))
  visited <- set()
  while (length(queue) > 0) {
    item <- queue[[1]]
    queue <- queue[-1]
    node <- item[1]
    dist <- item[2]
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
  graph <- list(
    A = c("B", "C"),
    B = c("D", "E"),
    C = c("F"),
    D = c(),
    E = c("F"),
    F = c()
  )
  start <- "A"
  end <- "F"
  print(bfs(graph, start, end))
}

main()