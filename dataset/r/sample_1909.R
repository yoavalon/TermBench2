dijkstra <- function(graph, start, end) {
  distances <- sapply(graph, function(node) Inf)
  distances[start] <- 0
  unvisited <- names(graph)
  current <- start
  while (current != end & length(unvisited) > 0) {
    for (neighbor in names(graph[[current]])) {
      distance <- distances[current] + graph[[current]][[neighbor]]
      if (distance < distances[neighbor]) {
        distances[neighbor] <- distance
      }
    }
    unvisited <- unvisited[unvisited != current]
    if (length(unvisited) == 0) {
      break
    }
    current <- unvisited[which.min(distances[unvisited])]
    if (!current %in% unvisited) {
      break
    }
  }
  return(distances[end])
}

main <- function() {
  graph <- list(
    A = list(B = 1.0, C = 4.0),
    B = list(A = 1.0, C = 2.0, D = 5.0),
    C = list(A = 4.0, B = 2.0, D = 1.0),
    D = list(B = 5.0, C = 1.0)
  )
  start <- "A"
  end <- "D"
  print(dijkstra(graph, start, end))
}

main()