SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(nodes = "list", edges = "list", demand = "numeric", path = "list"),
  methods = list(
    initialize = function(nodes, edges, demand) {
      .self$nodes <- nodes
      .self$edges <- edges
      .self$demand <- demand
      .self$path <- list()
    },
    optimize = function() {
      .self$_find_path(0, 0, 0)
    },
    _find_path = function(current_node, current_cost, current_demand) {
      if (current_node == length(.self$nodes) - 1) {
        if (current_demand == .self$demand) {
          .self$path <- c(.self$path, current_node)
          return(TRUE)
        }
        return(FALSE)
      }
      for (i in 1:length(.self$edges[[current_node + 1]])) {
        neighbor <- .self$edges[[current_node + 1]][[i]][[1]]
        cost <- .self$edges[[current_node + 1]][[i]][[2]]
        if (.self$_find_path(neighbor - 1, current_cost + cost, current_demand + 1)) {
          .self$path <- c(current_node, .self$path)
          return(TRUE)
        }
      }
      return(FALSE)
    }
  )
)

DemandBalancer <- setRefClass("DemandBalancer",
  fields = list(optimizer = "SupplyChainOptimizer"),
  methods = list(
    initialize = function(nodes, edges, demand) {
      .self$optimizer <- new("SupplyChainOptimizer", nodes = nodes, edges = edges, demand = demand)
    },
    balance = function() {
      .self$optimizer$optimize()
      return(.self$optimizer$path)
    }
  )
)

main <- function() {
  nodes <- list(0, 1, 2, 3, 4)
  edges <- list(
    list(c(2, 10), c(3, 15)),
    list(c(4, 5)),
    list(c(4, 10)),
    list(c(5, 20)),
    list()
  )
  demand <- 3
  balancer <- new("DemandBalancer", nodes = nodes, edges = edges, demand = demand)
  result <- balancer$balance()
  print(result)
}

main()