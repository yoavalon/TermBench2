graph_traversal <- function(graph, start, end) {
  queue <- list(list(start, list(start)))
  visited <- c()
  
  while (length(queue) > 0) {
    node <- queue[[1]][[1]]
    path <- queue[[1]][[2]]
    queue <- queue[-1]
    
    if (node == end) {
      return(path)
    }
    
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph[[node]]) {
        queue <- append(queue, list(list(neighbor, c(path, neighbor))))
      }
    }
  }
}

main <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  print(graph_traversal(graph, 'A', 'F'))
}

main()