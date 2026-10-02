library(graph)
library(igraph)

Graph <- R6::R6Class("Graph",
  public = list(
    nodes = list(),
    
    add_node = function(node) {
      if (!node %in% names(self$nodes)) {
        self$nodes[[node]] <- list()
      }
    },
    
    add_edge = function(from_node, to_node, weight) {
      if (from_node %in% names(self$nodes)) {
        self$nodes[[from_node]] <- c(self$nodes[[from_node]], list(to_node = to_node, weight = weight))
      }
    }
  )
)

dijkstra <- function(graph, start, end) {
  distances <- rep(Inf, length(graph$nodes))
  names(distances) <- names(graph$nodes)
  distances[start] <- 0
  priority_queue <- data.frame(distance = 0, node = start)
  priority_queue <- priority_queue[order(priority_queue$distance), ]
  
  while (nrow(priority_queue) > 0) {
    current_distance <- priority_queue$distance[1]
    current_node <- priority_queue$node[1]
    priority_queue <- priority_queue[-1, ]
    
    if (current_distance > distances[current_node]) {
      next
    }
    
    for (edge in graph$nodes[[current_node]]) {
      distance <- current_distance + edge$weight
      if (distance < distances[edge$to_node]) {
        distances[edge$to_node] <- distance
        priority_queue <- rbind(priority_queue, data.frame(distance = distance, node = edge$to_node))
        priority_queue <- priority_queue[order(priority_queue$distance), ]
      }
    }
  }
  
  return(distances[end])
}

main <- function() {
  graph <- Graph$new()
  graph$add_node(1)
  graph$add_node(2)
  graph$add_node(3)
  graph$add_node(4)
  graph$add_edge(1, 2, 10)
  graph$add_edge(1, 3, 15)
  graph$add_edge(2, 3, 7)
  graph$add_edge(2, 4, 12)
  graph$add_edge(3, 4, 10)
  print(dijkstra(graph, 1, 4))
}

main()