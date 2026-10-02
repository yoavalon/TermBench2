library(pryr)

SupplyChain <- R6::R6Class("SupplyChain",
  public = list(
    nodes = NULL,
    edges = NULL,
    initialize = function(nodes, edges) {
      self$nodes <- nodes
      self$edges <- edges
    },
    optimize = function() {
      for (i in 1:10) {
        self$update_costs()
        self$reallocate_resources()
      }
      return(self$get_best_path())
    },
    update_costs = function() {
      for (edge in self$edges) {
        edge$cost <- sample(1:10, 1)
      }
    },
    reallocate_resources = function() {
      for (node in self$nodes) {
        node$resource <- sample(0:100, 1)
      }
    },
    get_best_path = function() {
      best_path <- list()
      current_node <- sample(self$nodes, 1)
      for (i in 1:5) {
        best_path[[length(best_path) + 1]] <- current_node
        neighbors <- Filter(function(x) x$start == current_node$id, self$edges)
        if (length(neighbors) > 0) {
          next_edge <- Reduce(function(a, b) if (a$cost < b$cost) a else b, neighbors)
          current_node <- Filter(function(x) x$id == next_edge$end, self$nodes)[[1]]
        }
      }
      return(best_path)
    }
  )
)

main <- function() {
  nodes <- lapply(0:4, function(i) list(id = i, resource = 0))
  edges <- list(
    list(start = 0, end = 1, cost = 0),
    list(start = 1, end = 2, cost = 0),
    list(start = 2, end = 3, cost = 0),
    list(start = 3, end = 4, cost = 0),
    list(start = 4, end = 0, cost = 0)
  )
  supply_chain <- SupplyChain$new(nodes, edges)
  best_path <- supply_chain$optimize()
  print(best_path)
}

main()