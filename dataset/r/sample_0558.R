Graph <- R6::R6Class("Graph",
  public = list(
    nodes = list(),
    
    add_edge = function(u, v, weight = 1) {
      if (u %in% names(self$nodes)) {
        self$nodes[[u]] <- c(self$nodes[[u]], list(v = v, weight = weight))
      } else {
        self$nodes[[u]] <- list(list(v = v, weight = weight))
      }
      if (!(v %in% names(self$nodes))) {
        self$nodes[[v]] <- list()
      }
    }
  )
)

dijkstra <- function(graph, start) {
  distances <- setNames(rep(Inf, length(graph$nodes)), names(graph$nodes))
  distances[start] <- 0
  unvisited <- names(graph$nodes)
  while (length(unvisited) > 0) {
    current <- unvisited[which.min(distances[unvisited])]
    unvisited <- unvisited[unvisited != current]
    for (edge in graph$nodes[[current]]) {
      distance <- distances[current] + edge$weight
      if (distance < distances[edge$v]) {
        distances[edge$v] <- distance
      }
    }
  }
  return(distances)
}

find_shortest_path <- function(graph, start, end) {
  distances <- dijkstra(graph, start)
  path <- c()
  current <- end
  while (current != start) {
    path <- c(path, current)
    for (edge in graph$nodes[[current]]) {
      if (distances[current] == distances[edge$v] + edge$weight) {
        current <- edge$v
        break
      }
    }
  }
  path <- c(path, start)
  return(rev(path))
}

main <- function() {
  graph <- Graph$new()
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('C', 'D', 3)
  graph$add_edge('D', 'A', 4)
  start_node <- 'A'
  end_node <- 'D'
  shortest_path <- find_shortest_path(graph, start_node, end_node)
  print(paste('Shortest path:', paste(shortest_path, collapse = ' -> ')))
}

main()