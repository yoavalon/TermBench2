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
      .self$graph[u + 1, v + 1] <- w
      .self$graph[v + 1, u + 1] <- w
    },
    print_solution = function(dist) {
      cat("Vertex\tDistance from Source\n")
      for (node in 0:(.self$V - 1)) {
        cat(node, "\t", dist[node + 1], "\n")
      }
    },
    min_distance = function(dist, spt_set) {
      min_val <- Inf
      min_index <- -1
      for (v in 0:(.self$V - 1)) {
        if (dist[v + 1] < min_val && !spt_set[v + 1]) {
          min_val <- dist[v + 1]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src + 1] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (cout in 0:(.self$V - 1)) {
        u <- .self$min_distance(dist, spt_set)
        spt_set[u + 1] <- TRUE
        for (v in 0:(.self$V - 1)) {
          if (.self$graph[u + 1, v + 1] > 0 && !spt_set[v + 1] && (dist[v + 1] > dist[u + 1] + .self$graph[u + 1, v + 1])) {
            dist[v + 1] <- dist[u + 1] + .self$graph[u + 1, v + 1]
          }
        }
      }
      .self$print_solution(dist)
    }
  )
)

main <- function() {
  g <- new("Graph", vertices = 9)
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
  g$dijkstra(0)
}

main()