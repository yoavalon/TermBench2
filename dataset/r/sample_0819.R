SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(
    nodes = "numeric",
    edges = "matrix",
    demand = "numeric",
    supply = "numeric",
    flow = "matrix"
  ),
  methods = list(
    initialize = function(nodes, edges, demand, supply) {
      .self$nodes <- nodes
      .self$edges <- edges
      .self$demand <- demand
      .self$supply <- supply
      .self$flow <- matrix(0, nrow = nodes, ncol = nodes)
    },
    find_path = function(source, sink, parent) {
      visited <- rep(FALSE, .self$nodes)
      queue <- c(source)
      visited[source] <- TRUE
      while (length(queue) > 0) {
        u <- queue[1]
        queue <- queue[-1]
        for (v in 1:.self$nodes) {
          if (!visited[v] && .self$flow[u, v] < .self$edges[u, v]) {
            queue <- c(queue, v)
            visited[v] <- TRUE
            parent[v] <- u
            if (v == sink) {
              return(TRUE)
            }
          }
        }
      }
      return(FALSE)
    },
    max_flow = function(source, sink) {
      parent <- rep(-1, .self$nodes)
      max_flow_value <- 0
      while (.self$find_path(source, sink, parent)) {
        path_flow <- Inf
        s <- sink
        while (s != source) {
          path_flow <- min(path_flow, .self$edges[parent[s], s] - .self$flow[parent[s], s])
          s <- parent[s]
        }
        v <- sink
        while (v != source) {
          u <- parent[v]
          .self$flow[u, v] <- .self$flow[u, v] + path_flow
          .self$flow[v, u] <- .self$flow[v, u] - path_flow
          v <- parent[v]
        }
        max_flow_value <- max_flow_value + path_flow
      }
      return(max_flow_value)
    }
  )
)

main <- function() {
  nodes <- 6
  edges <- matrix(c(0, 16, 13, 0, 0, 0, 0, 0, 10, 12, 0, 0, 0, 4, 0, 0, 14, 0, 0, 0, 9, 0, 0, 20, 0, 0, 0, 7, 0, 4, 0, 0, 0, 0, 0, 0), nrow = nodes, byrow = TRUE)
  demand <- c(0, 0, 0, 0, 0, 25)
  supply <- c(25, 0, 0, 0, 0, 0)
  optimizer <- new("SupplyChainOptimizer", nodes, edges, demand, supply)
  result <- optimizer$max_flow(1, 6)
  cat('Maximum flow from source to sink is', result, '\n')
}

main()