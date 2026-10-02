library(graph)
library(igraph)

dijkstra <- function(graph, start, end) {
  dist <- rep(Inf, vcount(graph))
  vnames <- V(graph)$name
  dist[which(vnames == start)] <- 0
  queue <- list(c(0, start))
  while (length(queue) > 0) {
    current_dist <- queue[[1]][1]
    current_node <- queue[[1]][2]
    queue <- queue[-1]
    if (current_dist > dist[which(vnames == current_node)]) {
      next
    }
    neighbors <- neighbors(graph, which(vnames == current_node))
    for (neighbor in neighbors) {
      distance <- current_dist + E(graph)[V(graph) %--% V(graph)[name == vnames[neighbor]]]$weight
      if (distance < dist[neighbor]) {
        dist[neighbor] <- distance
        queue <- append(queue, list(c(distance, vnames[neighbor])), after = length(queue))
        queue <- sort(queue, decreasing = TRUE)
      }
    }
  }
  return(dist[which(vnames == end)])
}

main <- function() {
  graph <- graph.formula(A-B:1, A-C:4, B-A:1, B-C:2, B-D:5, C-A:4, C-B:2, C-D:1, D-B:5, D-C:1)
  E(graph)$weight <- c(1, 4, 1, 2, 5, 4, 2, 1, 5, 1)
  start <- 'A'
  end <- 'D'
  result <- dijkstra(graph, start, end)
  print(result)
}

main()