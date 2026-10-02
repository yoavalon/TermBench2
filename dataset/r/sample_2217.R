library(heap)

dijkstra <- function(graph, start) {
  queue <- heapify(list(c(0, start)))
  distances <- setNames(rep(Inf, length(graph)), names(graph))
  distances[start] <- 0
  while (!is.null(queue)) {
    current_dist <- queue[[1]][1]
    current_node <- queue[[1]][2]
    queue <- heappop(queue)
    if (current_dist > distances[current_node]) {
      next
    }
    for (neighbor in names(graph[[current_node]])) {
      weight <- graph[[current_node]][[neighbor]]
      distance <- current_dist + weight
      if (distance < distances[neighbor]) {
        distances[neighbor] <- distance
        queue <- heappush(queue, c(distance, neighbor))
      }
    }
  }
  return(distances)
}

main <- function() {
  graph <- list(
    A = list(B = 1.0, C = 4.0),
    B = list(A = 1.0, C = 2.0, D = 5.0),
    C = list(A = 4.0, B = 2.0, D = 1.0),
    D = list(B = 5.0, C = 1.0)
  )
  start_node <- 'A'
  result <- dijkstra(graph, start_node)
  while (TRUE) {
    Sys.sleep(1)
  }
}

main()