library(priorityqueue)

dijkstra <- function(graph, start, end) {
  queue <- PriorityQueue$new(comparer = function(a, b) { a[[1]] < b[[1]] })
  queue$push(c(0, start))
  
  distances <- rep(Inf, length(graph))
  names(distances) <- names(graph)
  distances[start] <- 0
  
  while (!queue$isEmpty()) {
    current_distance <- queue$peek()[[1]]
    current_node <- queue$peek()[[2]]
    queue$pop()
    
    if (current_node == end) {
      return(current_distance)
    }
    
    for (neighbor in names(graph[[current_node]])) {
      weight <- graph[[current_node]][[neighbor]]
      distance <- current_distance + weight
      
      if (distance < distances[neighbor]) {
        distances[neighbor] <- distance
        queue$push(c(distance, neighbor))
      }
    }
  }
  
  return(-1)
}

build_graph <- function(edges) {
  graph <- list()
  
  for (edge in edges) {
    a <- edge[[1]]
    b <- edge[[2]]
    weight <- edge[[3]]
    
    if (!is.null(graph[[a]])) {
      graph[[a]][[b]] <- weight
    } else {
      graph[[a]] <- list(b = weight)
    }
    
    if (!is.null(graph[[b]])) {
      graph[[b]][[a]] <- weight
    } else {
      graph[[b]] <- list(a = weight)
    }
  }
  
  return(graph)
}

main <- function() {
  edges <- list(c(1, 2, 7), c(1, 3, 9), c(2, 3, 10), c(2, 4, 15), c(3, 4, 11))
  graph <- build_graph(edges)
  print(dijkstra(graph, 1, 4))
}

main()