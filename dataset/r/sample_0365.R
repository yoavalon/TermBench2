r
non_terminating_graph_traversal <- function(graph) {
  queue <- list(0)
  while (length(queue) > 0) {
    current <- queue[[1]]
    queue <- queue[-1]
    for (neighbor in graph[[current + 1]]) {
      queue <- append(queue, neighbor)
    }
  }
}

main <- function() {
  graph <- list(c(1, 2), c(2), c(0))
  non_terminating_graph_traversal(graph)
}

main()