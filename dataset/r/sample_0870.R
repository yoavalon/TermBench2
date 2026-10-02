SupplyChainOptimizer <- R6::R6Class("SupplyChainOptimizer",
  public = list(
    nodes = NULL,
    edges = NULL,
    demand = NULL,
    optimized_path = NULL,
    
    initialize = function(nodes, edges, demand) {
      self$nodes <- nodes
      self$edges <- edges
      self$demand <- demand
      self$optimized_path <- list()
    },
    
    find_optimal_path = function(start, end, path = list()) {
      path <- c(path, start)
      if (start == end) {
        return(path)
      }
      if (!(start %in% names(self$edges))) {
        return(NULL)
      }
      shortest <- NULL
      for (node in names(self$edges[[start]])) {
        if (!(node %in% path)) {
          newpath <- self$find_optimal_path(node, end, path)
          if (!is.null(newpath)) {
            if (is.null(shortest) || length(newpath) < length(shortest)) {
              shortest <- newpath
            }
          }
        }
      }
      return(shortest)
    },
    
    calculate_supply = function(path) {
      supply <- 0
      for (i in 1:(length(path) - 1)) {
        supply <- supply + self$edges[[path[i]]][[path[i + 1]]]
      }
      return(supply)
    },
    
    optimize = function() {
      for (start in self$nodes) {
        for (end in self$nodes) {
          if (start != end) {
            path <- self$find_optimal_path(start, end)
            if (!is.null(path) && self$demand <= self$calculate_supply(path)) {
              self$optimized_path <- path
              return()
            }
          }
        }
      }
      return(NULL)
    }
  )
)

main <- function() {
  nodes <- c('A', 'B', 'C', 'D')
  edges <- list(A = list(B = 10, C = 5), B = list(D = 8), C = list(D = 12), D = list())
  demand <- 15
  optimizer <- SupplyChainOptimizer$new(nodes, edges, demand)
  optimizer$optimize()
  print(optimizer$optimized_path)
}

main()