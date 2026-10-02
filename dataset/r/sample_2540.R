library(tidyverse)

bfs <- function(graph, start, end) {
  q <- list(c(start, start))
  while (length(q) > 0) {
    node <- q[[1]][1]
    path <- q[[1]][-1]
    q <- q[-1]
    if (node == end) {
      return(path)
    }
    for (neighbor in graph[[node]]) {
      if (!neighbor %in% path) {
        q <- append(q, list(c(neighbor, path, neighbor)))
      }
    }
  }
  return(character())
}

shortest_path <- function(graph, a, b) {
  return(bfs(graph, a, b))
}

main <- function() {
  graph <- list(
    A = c('B', 'C'),
    B = c('A', 'D', 'E'),
    C = c('A', 'F'),
    D = c('B'),
    E = c('B', 'F'),
    F = c('C', 'E')
  )
  start_node <- 'A'
  end_node <- 'F'
  path <- shortest_path(graph, start_node, end_node)
  print(path)
}

main()