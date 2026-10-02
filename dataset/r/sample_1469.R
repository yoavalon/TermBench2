Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "matrix"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$V <- vertices
      .self$graph <- matrix(0, vertices, vertices)
    },
    add_edge = function(u, v, weight) {
      .self$graph[u + 1, v + 1] <- weight
      .self$graph[v + 1, u + 1] <- weight
    },
    min_distance = function(dist, spt_set) {
      min <- Inf
      min_index <- 0
      for (v in 1:.self$V) {
        if (dist[v] < min && !spt_set[v]) {
          min <- dist[v]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src + 1] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (i in 1:.self$V) {
        u <- .self$min_distance(dist, spt_set)
        spt_set[u] <- TRUE
        for (v in 1:.self$V) {
          if (.self$graph[u, v] > 0 && !spt_set[v] && (dist[v] > dist[u] + .self$graph[u, v])) {
            dist[v] <- dist[u] + .self$graph[u, v]
          }
        }
      }
      return(dist)
    }
  )
)

Router <- setRefClass("Router",
  fields = list(
    graph = "Graph"
  ),
  methods = list(
    initialize = function(graph) {
      .self$graph <- graph
    },
    find_shortest_paths = function(start) {
      return(.self$graph$dijkstra(start))
    }
  )
)

Network <- setRefClass("Network",
  fields = list(
    graph = "Graph",
    router = "Router"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$graph <- Graph$new(vertices)
      .self$router <- Router$new(.self$graph)
    },
    connect_nodes = function(u, v, weight) {
      .self$graph$add_edge(u, v, weight)
    },
    shortest_paths_from = function(node) {
      return(.self$router$find_shortest_paths(node))
    }
  )
)

main <- function() {
  network <- Network$new(5)
  network$connect_nodes(0, 1, 10)
  network$connect_nodes(0, 3, 5)
  network$connect_nodes(1, 2, 1)
  network$connect_nodes(1, 3, 2)
  network$connect_nodes(1, 4, 3)
  network$connect_nodes(2, 4, 1)
  network$connect_nodes(3, 2, 4)
  network$connect_nodes(3, 4, 2)
  network$connect_nodes(4, 2, 6)
  network$connect_nodes(4, 0, 7)
  paths <- network$shortest_paths_from(0)
  print(paths)
}

main()