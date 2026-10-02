find_shortest_path <- function(graph, start, end) {
  distances <- sapply(graph, function(x) Inf)
  distances[start] <- 0
  queue <- c(start)
  
  while (length(queue) > 0) {
    current <- queue[1]
    queue <- queue[-1]
    
    for (neighbor in names(graph[[current]])) {
      weight <- graph[[current]][[neighbor]]
      distance <- distances[current] + weight
      
      if (distance < distances[neighbor]) {
        distances[neighbor] <- distance
        queue <- c(queue, neighbor)
      }
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
  
  start <- 'A'
  end <- 'D'
  result <- find_shortest_path(graph, start, end)
  print(result)
}

main()