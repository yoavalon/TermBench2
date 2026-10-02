library(purrr)

bfs <- function(graph, start, end) {
  queue <- list(start)
  visited <- set()
  distances <- setNames(integer(), start)
  distances[start] <- 0
  
  while (length(queue) > 0) {
    node <- queue[[1]]
    queue <- queue[-1]
    
    if (node == end) {
      return(distances[node])
    }
    
    if (!node %in% visited) {
      visited <- c(visited, node)
      neighbors <- graph[[node]]
      
      for (neighbor in neighbors) {
        if (!neighbor %in% visited) {
          distances[neighbor] <- distances[node] + 1
          queue <- c(queue, neighbor)
        }
      }
    }
  }
  
  return(-1)
}

shortest_path <- function(graph, start, end) {
  return(bfs(graph, start, end))
}

if (identical(cmdArgs()[[1]], "--main")) {
  graph <- list(
    A = c("B", "C"),
    B = c("A", "D", "E"),
    C = c("A", "F"),
    D = c("B"),
    E = c("B", "F"),
    F = c("C", "E")
  )
  print(shortest_path(graph, "A", "F"))
}