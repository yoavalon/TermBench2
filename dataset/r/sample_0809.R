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
    },
    min_distance = function(dist, spt_set) {
      min <- Inf
      min_index <- -1
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
      dist[src+1] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (cout in 1:.self$V) {
        u <- .self$min_distance(dist, spt_set)
        spt_set[u] <- TRUE
        for (v in 1:.self$V) {
          if (!spt_set[v] && .self$graph[u, v] != 0 && dist[u] != Inf && (dist[u] + .self$graph[u, v] < dist[v])) {
            dist[v] <- dist[u] + .self$graph[u, v]
          }
        }
      }
      return(dist)
    }
  )
)

process_graph <- function() {
  g <- new("Graph", vertices = 9)
  g$add_edge(1, 2, 4)
  g$add_edge(1, 8, 8)
  g$add_edge(2, 3, 8)
  g$add_edge(2, 8, 11)
  g$add_edge(3, 4, 7)
  g$add_edge(3, 9, 2)
  g$add_edge(3, 6, 4)
  g$add_edge(4, 5, 9)
  g$add_edge(4, 6, 14)
  g$add_edge(5, 6, 10)
  g$add_edge(6, 7, 2)
  g$add_edge(7, 8, 1)
  g$add_edge(7, 9, 6)
  g$add_edge(8, 9, 7)
  return(g)
}

main <- function() {
  g <- process_graph()
  result <- g$dijkstra(1)
  print(result)
}

main()