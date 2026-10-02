library(pryr)

bfs <- function(graph, start, end) {
  queue <- list(c(start, start))
  visited <- c()
  while (length(queue) > 0) {
    node <- queue[[1]][1]
    path <- queue[[1]][2]
    queue <- queue[-1]
    if (node == end) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph[[node]]) {
        queue <- c(queue, list(c(neighbor, c(path, neighbor))))
      }
    }
  }
  return(NULL)
}

find_shortest_path <- function(graph, start, end) {
  path <- bfs(graph, start, end)
  if (!is.null(path)) {
    return(length(path) - 1)
  }
  return(-1)
}

main <- function() {
  graph <- list(A = c("B", "C"), B = c("A", "D", "E"), C = c("A", "F"), D = c("B"), E = c("B", "F"), F = c("C", "E"))
  start <- "A"
  end <- "F"
  print(find_shortest_path(graph, start, end))
}

main()