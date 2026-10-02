library(tidyverse)

bfs <- function(graph, start, end) {
  queue <- list(c(start, list(start)))
  visited <- set()
  while (length(queue) > 0) {
    current <- queue[[1]]
    queue <- queue[-1]
    node <- current[[1]]
    path <- current[[2]]
    if (node == end) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- union(visited, node)
      for (neighbor in graph[[node]]) {
        queue <- c(queue, list(c(neighbor, c(path, neighbor))))
      }
    }
  }
  return(list())
}

shortest_path <- function(graph, start, end) {
  return(bfs(graph, start, end))
}

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
print(shortest_path(graph, start, end))