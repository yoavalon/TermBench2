library(igraph)

Graph <- R6::R6Class("Graph",
  public = list(
    nodes = list(),
    
    add_node = function(node) {
      if (!node %in% names(self$nodes)) {
        self$nodes[[node]] <- list()
      }
    },
    
    add_edge = function(node1, node2, weight) {
      if (node1 %in% names(self$nodes) && node2 %in% names(self$nodes)) {
        self$nodes[[node1]] <- append(self$nodes[[node1]], list(node2 = node2, weight = weight), after = length(self$nodes[[node1]]))
        self$nodes[[node2]] <- append(self$nodes[[node2]], list(node1 = node1, weight = weight), after = length(self$nodes[[node2]]))
      }
    }
  )
)

dijkstra <- function(graph, start, goal) {
  queue <- list(list(cost = 0, node = start, path = list()))
  visited <- c()
  while (length(queue) > 0) {
    queue <- sort(queue, key = ~ .x$cost)
    item <- queue[[1]]
    cost <- item$cost
    node <- item$node
    path <- item$path
    queue <- queue[-1]
    if (!node %in% visited) {
      visited <- c(visited, node)
      path <- c(path, node)
      if (node == goal) {
        return(list(path, cost))
      }
      for (edge in graph$nodes[[node]]) {
        neighbor <- edge$node2
        weight <- edge$weight
        if (!neighbor %in% visited) {
          queue <- append(queue, list(list(cost = cost + weight, node = neighbor, path = path)), after = length(queue))
        }
      }
    }
  }
  return(list(list(), Inf))
}

find_paths <- function(graph, start, goal) {
  paths <- list()
  while (TRUE) {
    result <- dijkstra(graph, start, goal)
    path <- result[[1]]
    cost <- result[[2]]
    if (length(path) > 0) {
      paths <- append(paths, list(list(path, cost)), after = length(paths))
      graph$add_edge(path[length(path)], path[length(path)], 1)
    }
  }
}

main <- function() {
  graph <- Graph$new()
  graph$add_node('A')
  graph$add_node('B')
  graph$add_node('C')
  graph$add_node('D')
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('C', 'D', 3)
  graph$add_edge('D', 'A', 4)
  find_paths(graph, 'A', 'D')
}

main()