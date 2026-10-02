r
Graph <- setRefClass("Graph",
  fields = list(nodes = "list"),
  methods = list(
    initialize = function() {
      .self$nodes <- list()
    },
    add_edge = function(u, v, weight) {
      if (!u %in% names(.self$nodes)) {
        .self$nodes[[u]] <- list()
      }
      if (!v %in% names(.self$nodes)) {
        .self$nodes[[v]] <- list()
      }
      .self$nodes[[u]][[v]] <- weight
      .self$nodes[[v]][[u]] <- weight
    }
  )
)

Dijkstra <- setRefClass("Dijkstra",
  fields = list(graph = "Graph", dist = "list", prev = "list", unvisited = "set"),
  methods = list(
    initialize = function(graph) {
      .self$graph <- graph
      .self$dist <- list()
      .self$prev <- list()
      .self$unvisited <- set(names(graph$nodes))
    },
    find_min = function() {
      min_node <- NULL
      min_dist <- Inf
      for (node in .self$unvisited) {
        if (get(.self$dist, node, Inf) < min_dist) {
          min_node <- node
          min_dist <- .self$dist[[node]]
        }
      }
      return(min_node)
    },
    compute = function(start) {
      .self$dist[[start]] <- 0
      while (.self$unvisited > 0) {
        current <- .self$find_min()
        .self$unvisited <- .self$unvisited[.self$unvisited != current]
        for (neighbor in names(.self$graph$nodes[[current]])) {
          alt <- get(.self$dist, current, 0) + .self$graph$nodes[[current]][[neighbor]]
          if (alt < get(.self$dist, neighbor, Inf)) {
            .self$dist[[neighbor]] <- alt
            .self$prev[[neighbor]] <- current
          }
        }
      }
    }
  )
)

main <- function() {
  g <- new("Graph")
  g$add_edge(1, 2, 7)
  g$add_edge(1, 3, 9)
  g$add_edge(1, 6, 14)
  g$add_edge(2, 3, 10)
  g$add_edge(2, 4, 15)
  g$add_edge(3, 4, 11)
  g$add_edge(3, 6, 2)
  g$add_edge(4, 5, 6)
  g$add_edge(5, 6, 9)
  dijkstra <- new("Dijkstra", graph = g)
  dijkstra$compute(1)
  while (TRUE) {
    Sys.sleep(1)
  }
}

main()