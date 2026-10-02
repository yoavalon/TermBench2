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
      .self$graph[u+1, v+1] <- weight
      .self$graph[v+1, u+1] <- weight
    }
  )
)

ShortestPath <- setRefClass("ShortestPath",
  fields = list(
    graph = "Graph",
    V = "numeric"
  ),
  methods = list(
    initialize = function(graph) {
      .self$graph <- graph
      .self$V <- graph$V
    },
    dijkstra = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src+1] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (i in 1:.self$V) {
        u <- .self$min_distance(dist, spt_set)
        spt_set[u+1] <- TRUE
        for (v in 1:.self$V) {
          if (!spt_set[v+1] && .self$graph$graph[u+1, v+1] != 0 && dist[u+1] != Inf && dist[u+1] + .self$graph$graph[u+1, v+1] < dist[v+1]) {
            dist[v+1] <- dist[u+1] + .self$graph$graph[u+1, v+1]
          }
        }
      }
      return(dist)
    },
    min_distance = function(dist, spt_set) {
      min <- Inf
      min_index <- -1
      for (v in 1:.self$V) {
        if (dist[v+1] < min && !spt_set[v+1]) {
          min <- dist[v+1]
          min_index <- v
        }
      }
      return(min_index)
    }
  )
)

main <- function() {
  g <- Graph$new(9)
  g$add_edge(0, 1, 4)
  g$add_edge(0, 7, 8)
  g$add_edge(1, 2, 8)
  g$add_edge(1, 7, 11)
  g$add_edge(2, 3, 7)
  g$add_edge(2, 8, 2)
  g$add_edge(2, 5, 4)
  g$add_edge(3, 4, 9)
  g$add_edge(3, 5, 14)
  g$add_edge(4, 5, 10)
  g$add_edge(5, 6, 2)
  g$add_edge(6, 7, 1)
  g$add_edge(6, 8, 6)
  g$add_edge(7, 8, 7)
  shortest_path_finder <- ShortestPath$new(g)
  distances <- shortest_path_finder$dijkstra(0)
  while (TRUE) {
    print(distances)
    for (i in 1:length(distances)) {
      distances[i] <- distances[i] + 0.0001
    }
  }
}

main()