r
find_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, start))
  visited <- c()
  while (length(queue) > 0) {
    item <- queue[[1]]
    queue <- queue[-1]
    node <- item[1]
    path <- item[-1]
    if (node == end) {
      return(path)
    }
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph[[node]]) {
        queue <- append(queue, list(c(neighbor, path, neighbor)))
      }
    }
  }
  return(c())
}

main <- function() {
  graph <- list(A = c("B", "C"), B = c("A", "D", "E"), C = c("A", "F"), D = c("B"), E = c("B", "F"), F = c("C", "E"))
  path <- find_shortest_path(graph, "A", "F")
  print(path)
}

main()