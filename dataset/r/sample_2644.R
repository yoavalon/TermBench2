Graph <- R6::R6Class("Graph",
  public = list(
    nodes = NULL,
    edges = list(),
    
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    
    add_edge = function(u, v, weight) {
      if (!(u %in% names(self$edges))) {
        self$edges[[u]] <- list()
      }
      self$edges[[u]][[v]] <- weight
    },
    
    get_neighbors = function(node) {
      return(self$edges[[node]] %||% list())
    }
  )
)

Dijkstra <- R6::R6Class("Dijkstra",
  public = list(
    graph = NULL,
    start = NULL,
    distances = NULL,
    priority_queue = list(),
    
    initialize = function(graph, start) {
      self$graph <- graph
      self$start <- start
      self$distances <- setNames(rep(Inf, length(graph$nodes)), graph$nodes)
      self$distances[start] <- 0
      self$priority_queue <- list(list(0, start))
    },
    
    extract_min = function() {
      min_distance <- Inf
      min_node <- NULL
      for (item in self$priority_queue) {
        if (item[[1]] < min_distance) {
          min_distance <- item[[1]]
          min_node <- item[[2]]
        }
      }
      self$priority_queue <- self$priority_queue[!(sapply(self$priority_queue, function(x) all(x == c(min_distance, min_node))))]
      return(min_node)
    },
    
    update_distances = function(current, neighbors) {
      for (neighbor in names(neighbors)) {
        new_distance <- self$distances[current] + neighbors[[neighbor]]
        if (new_distance < self$distances[neighbor]) {
          self$distances[neighbor] <- new_distance
          self$priority_queue[[length(self$priority_queue) + 1]] <- list(new_distance, neighbor)
        }
      }
    },
    
    run = function() {
      while (length(self$priority_queue) > 0) {
        current <- self$extract_min()
        neighbors <- self$graph$get_neighbors(current)
        self$update_distances(current, neighbors)
      }
      return(self$distances)
    }
  )
)

main <- function() {
  nodes <- c('A', 'B', 'C', 'D', 'E')
  graph <- Graph$new(nodes)
  graph$add_edge('A', 'B', 1)
  graph$add_edge('A', 'C', 4)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('B', 'D', 5)
  graph$add_edge('C', 'D', 1)
  graph$add_edge('D', 'E', 3)
  dijkstra <- Dijkstra$new(graph, 'A')
  shortest_paths <- dijkstra$run()
  print(shortest_paths)
}

main()