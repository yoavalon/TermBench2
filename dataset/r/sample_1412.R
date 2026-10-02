r
Graph <- R6::R6Class("Graph",
  public = list(
    initialize = function() {
      self$edges <- list()
    },
    add_edge = function(node1, node2, weight) {
      if (!node1 %in% names(self$edges)) {
        self$edges[[node1]] <- list()
      }
      if (!node2 %in% names(self$edges)) {
        self$edges[[node2]] <- list()
      }
      self$edges[[node1]][[node2]] <- weight
      self$edges[[node2]][[node1]] <- weight
    },
    get_neighbors = function(node) {
      if (node %in% names(self$edges)) {
        return(self$edges[[node]])
      } else {
        return(list())
      }
    }
  )
)

Dijkstra <- R6::R6Class("Dijkstra",
  public = list(
    initialize = function(graph) {
      self$graph <- graph
    },
    find_shortest_path = function(start, end) {
      distances <- setNames(rep(Inf, length(self$graph$edges)), names(self$graph$edges))
      distances[[start]] <- 0
      unvisited <- names(self$graph$edges)
      while (length(unvisited) > 0) {
        current <- unvisited[which.min(sapply(unvisited, function(node) distances[[node]]))]
        unvisited <- unvisited[unvisited != current]
        if (current == end) {
          break
        }
        for (neighbor in names(self$graph$get_neighbors(current))) {
          distance <- distances[[current]] + self$graph$get_neighbors(current)[[neighbor]]
          if (distance < distances[[neighbor]]) {
            distances[[neighbor]] <- distance
          }
        }
      }
      return(distances[[end]])
    }
  )
)

main <- function() {
  g <- Graph$new()
  g$add_edge('A', 'B', 1)
  g$add_edge('B', 'C', 2)
  g$add_edge('C', 'D', 3)
  g$add_edge('A', 'D', 10)
  g$add_edge('B', 'D', 4)
  dijkstra <- Dijkstra$new(g)
  result <- dijkstra$find_shortest_path('A', 'D')
  print(result)
}

main()