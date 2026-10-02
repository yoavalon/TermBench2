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
    
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph[[node]]) {
        if (!neighbor %in% visited) {
          queue <- c(queue, list(c(neighbor, dist + 1)))
        }
      }
    }
  }
}

main <- function() {
  graph <- list(c(1, 2), c(2, 3), c(3, 4), c(4), c())
  print(find_shortest_path(graph, 0, 4))
}

main()