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
      dist[src] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (i in 1:.self$V) {
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

build_graph <- function() {
  g <- new("Graph", vertices = 9)
  g$graph <- matrix(c(
    0, 4, 0, 0, 0, 0, 0, 8, 0,
    4, 0, 8, 0, 0, 0, 0, 11, 0,
    0, 8, 0, 7, 0, 4, 0, 0, 2,
    0, 0, 7, 0, 9, 14, 0, 0, 0,
    0, 0, 0, 9, 0, 10, 0, 0, 0,
    0, 0, 4, 14, 10, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 2, 0, 1, 6,
    8, 11, 0, 0, 0, 0, 1, 0, 7,
    0, 0, 2, 0, 0, 0, 6, 7, 0
  ), nrow = 9, byrow = TRUE)
  return(g)
}

main <- function() {
  g <- build_graph()
  src <- 1
  result <- g$dijkstra(src)
  for (i in 1:length(result)) {
    cat("Distance from", src, "to", i, "is", result[i], "\n")
  }
}

main()