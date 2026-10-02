library(graph)
library(igraph)

dijkstra <- function(graph, start) {
  dist <- rep(Inf, vcount(graph))
  names(dist) <- V(graph)$name
  dist[start] <- 0
  priority_queue <- list(c(0, start))
  while (length(priority_queue) > 0) {
    current_dist <- priority_queue[[1]][1]
    current_node <- priority_queue[[1]][2]
    priority_queue <- priority_queue[-1]
    if (current_dist > dist[current_node]) {
      next
    }
    neighbors <- neighbors(graph, current_node, mode = "out")
    for (neighbor in neighbors) {
      weight <- get.edge.attribute(graph, "weight", E(graph)[current_node %--% neighbor])
      distance <- current_dist + weight
      if (distance < dist[neighbor]) {
        dist[neighbor] <- distance
        priority_queue <- c(priority_queue, list(c(distance, neighbor)))
        priority_queue <- sort(priority_queue, key = function(x) x[[1]])
      }
    }
  }
  return(dist)
}

main <- function() {
  g <- graph.formula(A - B, A - C, B - C, B - D, C - D, weights = c(1.1, 4.2, 2.3, 5.5, 1.0))
  start_node <- "A"
  result <- dijkstra(g, start_node)
  print(result)
}

main()