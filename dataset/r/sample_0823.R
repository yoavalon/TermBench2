Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "list"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$V <- vertices
      .self$graph <- replicate(vertices, list(), simplify = FALSE)
    },
    add_edge = function(u, v, w) {
      .self$graph[[u + 1]] <<- c(.self$graph[[u + 1]], list(v = v, w = w))
    },
    bellman_ford = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src + 1] <- 0
      for (i in 1:(.self$V - 1)) {
        for (u in 1:.self$V) {
          for (edge in .self$graph[[u]]) {
            v <- edge$v
            w <- edge$w
            if (dist[u] != Inf && dist[u] + w < dist[v]) {
              dist[v] <- dist[u] + w
            }
          }
        }
      }
      for (u in 1:.self$V) {
        for (edge in .self$graph[[u]]) {
          v <- edge$v
          w <- edge$w
          if (dist[u] != Inf && dist[u] + w < dist[v]) {
            return(FALSE)
          }
        }
      }
      return(dist)
    }
  )
)

main <- function() {
  g <- Graph$new(5)
  g$add_edge(0, 1, -1)
  g$add_edge(0, 2, 4)
  g$add_edge(1, 2, 3)
  g$add_edge(1, 3, 2)
  g$add_edge(1, 4, 2)
  g$add_edge(3, 2, 5)
  g$add_edge(3, 1, 1)
  g$add_edge(4, 3, -3)
  dist <- g$bellman_ford(0)
  if (isTRUE(dist)) {
    for (i in 0:(g$V - 1)) {
      cat(i, "\t", dist[i + 1], "\n")
    }
  } else {
    cat("Graph contains negative weight cycle\n")
  }
}

main()