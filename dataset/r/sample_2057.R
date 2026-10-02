Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "matrix"
  ),
  methods = list(
    min_distance = function(dist, spt_set) {
      min <- Inf
      for (v in 1:self$V) {
        if (dist[v] < min && !spt_set[v]) {
          min <- dist[v]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, self$V)
      dist[src] <- 0
      spt_set <- rep(FALSE, self$V)
      for (cout in 1:self$V) {
        u <- self$min_distance(dist, spt_set)
        spt_set[u] <- TRUE
        for (v in 1:self$V) {
          if (self$graph[u, v] > 0 && !spt_set[v] && (dist[v] > dist[u] + self$graph[u, v])) {
            dist[v] <- dist[u] + self$graph[u, v]
          }
        }
      }
      return(dist)
    }
  )
)

initialize_graph <- function() {
  g <- new("Graph", V = 9)
  g$graph <- matrix(c(0, 4, 0, 0, 0, 0, 0, 8, 0, 4, 0, 8, 0, 0, 0, 0, 11, 0, 0, 8, 0, 7, 0, 4, 0, 0, 2, 0, 0, 7, 0, 9, 14, 0, 0, 0, 0, 0, 9, 0, 10, 0, 0, 0, 0, 0, 4, 14, 10, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1, 6, 8, 11, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 2, 0, 0, 0, 0, 6, 7, 0), nrow = 9, byrow = TRUE)
  return(g)
}

main <- function() {
  g <- initialize_graph()
  result <- g$dijkstra(1)
  print(result)
}

main()