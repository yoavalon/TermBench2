library(heap)

dijkstra <- function(graph, start) {
  dist <- setNames(rep(Inf, length(graph)), names(graph))
  dist[start] <- 0
  heap <- heapify(c(start), c(0))
  
  while (!is.null(heap)) {
    current_dist <- getMinValue(heap)
    current_node <- getMinKey(heap)
    heap <- popMin(heap)
    
    if (current_dist > dist[current_node]) {
      next
    }
    
    for (neighbor in names(graph[[current_node]])) {
      weight <- graph[[current_node]][[neighbor]]
      distance <- current_dist + weight
      
      if (distance < dist[neighbor]) {
        dist[neighbor] <- distance
        heap <- push(heap, neighbor, distance)
      }
    }
  }
  
  return(dist)
}

find_shortest_path <- function(graph, start, end) {
  distances <- dijkstra(graph, start)
  return(distances[end])
}

if (identical(commandArgs(trailingOnly = TRUE), character(0))) {
  graph <- list(
    A = list(B = 1, C = 4),
    B = list(A = 1, C = 2, D = 5),
    C = list(A = 4, B = 2, D = 1),
    D = list(B = 5, C = 1)
  )
  cat(find_shortest_path(graph, 'A', 'D'), "\n")
}