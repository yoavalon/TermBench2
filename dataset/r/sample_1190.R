SupplyChain <- R6::R6Class("SupplyChain",
  public = list(
    nodes = NULL,
    edges = NULL,
    
    initialize = function(nodes, edges) {
      self$nodes <- nodes
      self$edges <- edges
    },
    
    optimize = function(start, end) {
      path <- self$find_path(start, end, list())
      if (!is.null(path)) {
        return(self$calculate_cost(path))
      }
      return(Inf)
    },
    
    find_path = function(current, end, visited) {
      visited <- c(visited, current)
      if (current == end) {
        return(list(current))
      }
      for (neighbor in self$get_neighbors(current)) {
        if (!neighbor %in% visited) {
          path <- self$find_path(neighbor, end, visited)
          if (!is.null(path)) {
            return(c(current, path))
          }
        }
      }
      return(NULL)
    },
    
    get_neighbors = function(node) {
      neighbors <- list()
      for (edge in self$edges) {
        if (edge[[1]] == node) {
          neighbors <- c(neighbors, edge[[2]])
        }
      }
      return(neighbors)
    },
    
    calculate_cost = function(path) {
      cost <- 0
      for (i in 1:(length(path) - 1)) {
        for (edge in self$edges) {
          if (edge[[1]] == path[i] && edge[[2]] == path[i + 1]) {
            cost <- cost + edge[[3]]
          }
        }
      }
      return(cost)
    }
  )
)

main <- function() {
  nodes <- c('A', 'B', 'C', 'D')
  edges <- list(c('A', 'B', 10), c('B', 'C', 20), c('C', 'D', 30), c('D', 'A', 40))
  supply_chain <- SupplyChain$new(nodes, edges)
  while (TRUE) {
    cost <- supply_chain$optimize('A', 'D')
    cat("Optimized cost:", cost, "\n")
  }
}

main()