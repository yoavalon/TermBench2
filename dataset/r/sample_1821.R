find_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, 0, list(start)))
  while (length(queue) > 0) {
    current <- queue[[1]]
    queue <- queue[-1]
    node <- current[1]
    cost <- current[2]
    visited <- current[3]
    if (node == end) {
      return(cost)
    }
    for (neighbor in names(graph[[node]])) {
      if (!(neighbor %in% visited)) {
        new_visited <- c(visited, neighbor)
        queue <- c(queue, list(c(neighbor, cost + graph[[node]][[neighbor]], new_visited)))
      }
    }
  }
  return(-1)
}

graph <- list(
  A = list(B = 1.0, C = 4.0),
  B = list(A = 1.0, D = 2.0),
  C = list(A = 4.0, D = 1.0),
  D = list(B = 2.0, C = 1.0)
)

print(find_shortest_path(graph, 'A', 'D'))