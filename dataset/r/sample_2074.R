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
    add_edge = function(u, v, w) {
      .self$graph[u+1, v+1] <- w
      .self$graph[v+1, u+1] <- w
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
          if (.self$graph[u, v] > 0 && !spt_set[v] && dist[v] > dist[u] + .self$graph[u, v]) {
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
  g$add_edge(0, 1, 4)
  g$add_edge(0, 7, 8)
  g$add_edge(1, 2, 8)
  g$add_edge(1, 7, 11)
  g$add_edge(2, 3, 7)
  g$add_edge(2, 5, 4)
  g$add_edge(2, 8, 2)
  g$add_edge(3, 4, 9)
  g$add_edge(3, 5, 14)
  g$add_edge(4, 5, 10)
  g$add_edge(5, 6, 2)
  g$add_edge(6, 7, 1)
  g$add_edge(6, 8, 6)
  g$add_edge(7, 8, 7)
  return(g)
}

main <- function() {
  g <- process_graph()
  distances <- g$dijkstra(0)
  for (node in 0:(length(distances)-1)) {
    cat(paste("Distance from 0 to", node, "is", distances[node+1], "\n"))
  }
}

main()