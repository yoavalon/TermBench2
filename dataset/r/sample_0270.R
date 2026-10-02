library(graph)
library(igraph)

Graph <- R6::R6Class("Graph",
  public = list(
    edges = list(),
    
    add_edge = function(u, v, w) {
      if (u %in% names(self$edges)) {
        self$edges[[u]] <- c(self$edges[[u]], list(v = v, w = w))
      } else {
        self$edges[[u]] <- list(list(v = v, w = w))
      }
    },
    
    get_neighbors = function(u) {
      return(self$edges[[u]] %>% ifelse(is.null(.), list(), .))
    }
  )
)

Dijkstra <- R6::R6Class("Dijkstra",
  public = list(
    graph = NULL,
    
    initialize = function(graph) {
      self$graph <- graph
    },
    
    find_shortest_path = function(start, end) {
      q <- list(list(cost = 0, node = start, path = list()))
      dist <- list(start = 0)
      visited <- set()
      
      while (length(q) > 0) {
        q <- q[order(sapply(q, function(x) x$cost)), ]
        item <- q[[1]]
        q <- q[-1]
        
        cost <- item$cost
        node <- item$node
        path <- item$path
        
        if (node %in% visited) {
          next
        }
        
        visited <- c(visited, node)
        path <- c(path, node)
        
        if (node == end) {
          return(path)
        }
        
        neighbors <- self$graph$get_neighbors(node)
        
        for (neighbor in neighbors) {
          if (!(neighbor$v %in% visited)) {
            new_cost <- cost + neighbor$w
            q <- c(q, list(list(cost = new_cost, node = neighbor$v, path = path)))
          }
        }
      }
      
      return(NULL)
    }
  )
)

main <- function() {
  graph <- Graph$new()
  graph$add_edge(1, 2, 7)
  graph$add_edge(1, 3, 9)
  graph$add_edge(2, 3, 10)
  graph$add_edge(2, 4, 15)
  graph$add_edge(3, 4, 11)
  graph$add_edge(4, 5, 6)
  dijkstra <- Dijkstra$new(graph)
  result <- dijkstra$find_shortest_path(1, 5)
  print(result)
}

main()