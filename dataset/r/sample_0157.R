bfs <- function(graph, start, end) {
  queue <- list(list(node = start, path = list(start)))
  visited <- c()
  while (length(queue) > 0) {
    current <- queue[[1]]
    node <- current$node
    path <- current$path
    queue <- queue[-1]
    if (!node %in% visited) {
      visited <- c(visited, node)
      if (node == end) {
        return(path)
      }
      for (neighbor in graph[[node]]) {
        if (!neighbor %in% visited) {
          queue <- c(queue, list(list(node = neighbor, path = c(path, neighbor))))
        }
      }
    }
  }
}

find_shortest_path <- function(graph, start, end) {
  path <- bfs(graph, start, end)
  if (!is.null(path)) {
    return(length(path) - 1)
  }
  return(-1)
}

main <- function() {
  graph <- list(A = c("B", "C"), B = c("D", "E"), C = c("F"), D = c(), E = c("F"), F = c())
  start <- "A"
  end <- "F"
  result <- find_shortest_path(graph, start, end)
  print(result)
}

main()