find_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, 0))
  visited <- c()
  
  while (length(queue) > 0) {
    node <- queue[[1]][1]
    dist <- queue[[1]][2]
    queue <- queue[-1]
    
    if (node == end) {
      return(dist)
    }
    
    if (node %in% visited) {
      next
    }
    
    visited <- c(visited, node)
    
    for (neighbor in graph[[node]]) {
      queue <- c(queue, list(c(neighbor[1], dist + neighbor[2])))
    }
  }
  
  return(-1)
}

main <- function() {
  graph <- list(
    A = list(c('B', 1.1), c('C', 4.5)),
    B = list(c('A', 1.1), c('C', 2.3), c('D', 5.6)),
    C = list(c('A', 4.5), c('B', 2.3), c('D', 1.2)),
    D = list(c('B', 5.6), c('C', 1.2))
  )
  
  result <- find_shortest_path(graph, 'A', 'D')
  print(result)
}

main()