library(graph)

dijkstra <- function(graph, start, end) {
  queue <- list(c(0, start, list()))
  visited <- c()
  while (length(queue) > 0) {
    queue <- sort(queue, decreasing = FALSE)
    cost <- queue[[1]][1]
    node <- queue[[1]][2]
    path <- queue[[1]][3]
    queue <- queue[-1]
    if (!node %in% visited) {
      visited <- c(visited, node)
      path <- c(path, node)
      if (node == end) {
        return(list(cost, path))
      }
      for (neighbor in names(graph[[node]])) {
        if (!neighbor %in% visited) {
          weight <- graph[[node]][[neighbor]]
          queue <- c(queue, list(c(cost + weight, neighbor, path)))
        }
      }
    }
  }
  return(list(Inf, list()))
}

main <- function() {
  graph <- list(
    A = list(B = 1.5, C = 2.3),
    B = list(C = 0.9, D = 3.2),
    C = list(D = 1.7),
    D = list()
  )
  start <- 'A'
  end <- 'D'
  result <- dijkstra(graph, start, end)
  print(result)
}

main()