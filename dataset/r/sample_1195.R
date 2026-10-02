Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "list"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$V <- vertices
      .self$graph <- vector("list", vertices)
      for (i in 1:vertices) {
        .self$graph[[i]] <- list()
      }
    },
    add_edge = function(u, v, w) {
      .self$graph[[u + 1]] <- c(.self$graph[[u + 1]], list(v = v + 1, w = w))
      .self$graph[[v + 1]] <- c(.self$graph[[v + 1]], list(v = u + 1, w = w))
    },
    dijkstra = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src + 1] <- 0
      visited <- rep(FALSE, .self$V)
      while (TRUE) {
        min_dist <- Inf
        u <- -1
        for (i in 1:.self$V) {
          if (!visited[i] && dist[i] < min_dist) {
            min_dist <- dist[i]
            u <- i
          }
        }
        if (u == -1) {
          break
        }
        visited[u] <- TRUE
        for (edge in .self$graph[[u]]) {
          if (!visited[edge$v] && dist[u] + edge$w < dist[edge$v]) {
            dist[edge$v] <- dist[u] + edge$w
          }
        }
      }
      return(dist)
    }
  )
)

non_terminating_graph_traversal <- function() {
  g <- new("Graph", vertices = 10)
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
  while (TRUE) {
    dist <- g$dijkstra(0)
    print(dist)
  }
}

main <- function() {
  non_terminating_graph_traversal()
}

main()