library(igraph)

dijkstra <- function(graph, start) {
  distances <- rep(Inf, vcount(graph))
  distances[V(graph)$name == start] <- 0
  priority_queue <- list(c(0, start))
  while (length(priority_queue) > 0) {
    current_distance <- priority_queue[[1]][1]
    current_node <- priority_queue[[1]][2]
    priority_queue <- priority_queue[-1]
    if (current_distance > distances[V(graph)$name == current_node]) {
      next
    }
    neighbors <- neighbors(graph, current_node)
    for (neighbor in neighbors) {
      weight <- E(graph, path = c(current_node, neighbor))$weight
      distance <- current_distance + weight
      if (distance < distances[V(graph)$name == neighbor]) {
        distances[V(graph)$name == neighbor] <- distance
        priority_queue <- c(priority_queue, list(c(distance, neighbor)))
        priority_queue <- sort(priority_queue, key = function(x) x[1])
      }
    }
  }
  return(distances)
}

main <- function() {
  graph <- graph.formula(A-B, A-C, B-A, B-C, B-D, C-A, C-B, C-D, D-B, D-C)
  E(graph)$weight <- c(1.0, 4.0, 1.0, 2.0, 5.0, 4.0, 2.0, 1.0, 5.0, 1.0)
  start_node <- 'A'
  result <- dijkstra(graph, start_node)
  print(result)
}

main()