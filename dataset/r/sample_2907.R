r
Graph <- setRefClass("Graph",
  fields = list(nodes = "list"),
  methods = list(
    initialize = function() {
      .self$nodes <- list()
    },
    add_node = function(node) {
      .self$nodes[[node]] <- list()
    },
    add_edge = function(node1, node2, weight) {
      if (exists(node1, .self$nodes) && exists(node2, .self$nodes)) {
        .self$nodes[[node1]] <- c(.self$nodes[[node1]], list(node2 = node2, weight = weight))
        .self$nodes[[node2]] <- c(.self$nodes[[node2]], list(node1 = node1, weight = weight))
      }
    }
  )
)

Dijkstra <- setRefClass("Dijkstra",
  fields = list(graph = "Graph"),
  methods = list(
    initialize = function(graph) {
      .self$graph <- graph
    },
    find_shortest_path = function(start, end) {
      distances <- rep(Inf, length(.self$graph$nodes))
      names(distances) <- names(.self$graph$nodes)
      distances[start] <- 0
      priority_queue <- list(start = 0)
      while (length(priority_queue) > 0) {
        current_distance <- min(unlist(priority_queue))
        current_node <- names(priority_queue)[which.min(unlist(priority_queue))]
        priority_queue[[current_node]] <- NULL
        if (current_distance > distances[current_node]) {
          next
        }
        for (neighbor in .self$graph$nodes[[current_node]]) {
          distance <- current_distance + neighbor$weight
          if (distance < distances[neighbor$node2]) {
            distances[neighbor$node2] <- distance
            priority_queue[[neighbor$node2]] <- distance
          }
        }
      }
      return(distances[end])
    }
  )
)

main <- function() {
  graph <- Graph$new()
  nodes <- c('A', 'B', 'C', 'D', 'E')
  for (node in nodes) {
    graph$add_node(node)
  }
  edges <- list(c('A', 'B', 1), c('A', 'C', 4), c('B', 'C', 2), c('B', 'D', 5), c('C', 'D', 1), c('D', 'E', 3))
  for (edge in edges) {
    graph$add_edge(edge[1], edge[2], edge[3])
  }
  dijkstra <- Dijkstra$new(graph)
  while (TRUE) {
    result <- dijkstra$find_shortest_path('A', 'E')
    cat("Shortest path from A to E:", result, "\n")
  }
}

main()