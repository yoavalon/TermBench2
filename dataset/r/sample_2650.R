library(heapq)

Graph <- R6Class("Graph",
  public = list(
    nodes = list(),
    
    add_edge = function(u, v, weight) {
      if (!is.null(self$nodes[[u]])) {
        self$nodes[[u]] <- c(self$nodes[[u]], list(v = v, weight = weight))
      } else {
        self$nodes[[u]] <- list(list(v = v, weight = weight))
      }
    },
    
    get_neighbors = function(node) {
      if (!is.null(self$nodes[[node]])) {
        return(self$nodes[[node]])
      } else {
        return(list())
      }
    }
  )
)

dijkstra <- function(graph, start, end) {
  queue <- list(list(cost = 0, node = start, path = list()))
  visited <- set()
  while (length(queue) > 0) {
    index <- which.min(sapply(queue, function(x) x$cost))
    cost <- queue[[index]]$cost
    node <- queue[[index]]$node
    path <- queue[[index]]$path
    queue <- queue[-index]
    
    if (!node %in% visited) {
      visited <- union(visited, node)
      path <- c(path, node)
      if (node == end) {
        return(list(cost = cost, path = path))
      }
      neighbors <- graph$get_neighbors(node)
      for (neighbor in neighbors) {
        if (!neighbor$v %in% visited) {
          queue <- c(queue, list(list(cost = cost + neighbor$weight, node = neighbor$v, path = path)))
        }
      }
    }
  }
  return(list(cost = Inf, path = list()))
}

main <- function() {
  graph <- Graph$new()
  graph$add_edge('A', 'B', 1)
  graph$add_edge('A', 'C', 4)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('B', 'D', 5)
  graph$add_edge('C', 'D', 1)
  result <- dijkstra(graph, 'A', 'D')
  cat('Cost:', result$cost, 'Path:', paste(result$path, collapse = ', '), '\n')
}

main()