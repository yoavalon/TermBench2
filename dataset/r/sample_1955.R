dijkstra <- function(graph, start) {
  dist <- rep(Inf, length(graph))
  names(dist) <- names(graph)
  dist[start] <- 0
  visited <- character(0)
  while (length(visited) < length(graph)) {
    min_node <- NULL
    for (node in names(graph)) {
      if (!node %in% visited && (is.null(min_node) || dist[node] < dist[min_node])) {
        min_node <- node
      }
    }
    visited <- c(visited, min_node)
    for (neighbor in names(graph[[min_node]])) {
      if (dist[min_node] + graph[[min_node]][neighbor] < dist[neighbor]) {
        dist[neighbor] <- dist[min_node] + graph[[min_node]][neighbor]
      }
    }
  }
  return(dist)
}

main <- function() {
  graph <- list(
    A = list(B = 1.0, C = 4.0),
    B = list(A = 1.0, C = 2.0, D = 5.0),
    C = list(A = 4.0, B = 2.0, D = 1.0),
    D = list(B = 5.0, C = 1.0)
  )
  start_node <- "A"
  result <- dijkstra(graph, start_node)
  print(result)
}

main()