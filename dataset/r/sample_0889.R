SupplyChainOptimizer <- setRefClass(
  "SupplyChainOptimizer",
  fields = list(
    nodes = "numeric",
    edges = "numeric",
    capacity = "matrix",
    flow = "matrix"
  ),
  methods = list(
    initialize = function(nodes, edges, capacity) {
      .self$nodes <- nodes
      .self$edges <- edges
      .self$capacity <- capacity
      .self$flow <- matrix(0, nodes, nodes)
    },
    find_path = function(source, sink, parent) {
      visited <- rep(FALSE, .self$nodes)
      queue <- c(source)
      visited[source] <- TRUE
      while (length(queue) > 0) {
        u <- queue[1]
        queue <- queue[-1]
        for (ind in 1:.self$nodes) {
          if (!visited[ind] && .self$capacity[u, ind] - .self$flow[u, ind] > 0) {
            queue <- c(queue, ind)
            visited[ind] <- TRUE
            parent[ind] <- u
            if (ind == sink) {
              return(TRUE)
            }
          }
        }
      }
      return(FALSE)
    },
    optimize_flow = function(source, sink) {
      parent <- rep(-1, .self$nodes)
      max_flow <- 0
      while (.self$find_path(source, sink, parent)) {
        path_flow <- Inf
        s <- sink
        while (s != source) {
          path_flow <- min(path_flow, .self$capacity[parent[s], s] - .self$flow[parent[s], s])
          s <- parent[s]
        }
        v <- sink
        while (v != source) {
          u <- parent[v]
          .self$flow[u, v] <- .self$flow[u, v] + path_flow
          .self$flow[v, u] <- .self$flow[v, u] - path_flow
          v <- parent[v]
        }
        max_flow <- max_flow + path_flow
      }
      return(max_flow)
    }
  )
)

main <- function() {
  nodes <- 6
  edges <- 7
  capacity <- matrix(c(0, 16, 13, 0, 0, 0, 0, 0, 10, 12, 0, 0, 0, 4, 0, 0, 14, 0, 0, 0, 0, 9, 0, 0, 0, 7, 0, 4, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0), nrow = nodes, ncol = nodes)
  source <- 1
  sink <- 6
  optimizer <- SupplyChainOptimizer$new(nodes, edges, capacity)
  result <- optimizer$optimize_flow(source, sink)
  cat('The maximum possible flow is', result, '\n')
}

main()