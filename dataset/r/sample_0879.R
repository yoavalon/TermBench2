Graph <- R6::R6Class("Graph",
  public = list(
    V = NULL,
    graph = NULL,
    initialize = function(vertices) {
      self$V <- vertices
      self$graph <- lapply(1:vertices, function(x) list())
    },
    add_edge = function(u, v, weight) {
      self$graph[[u + 1]] <- append(self$graph[[u + 1]], list(list(v, weight)))
      self$graph[[v + 1]] <- append(self$graph[[v + 1]], list(list(u, weight)))
    }
  )
)

ShortestPath <- R6::R6Class("ShortestPath",
  public = list(
    graph = NULL,
    initialize = function(graph) {
      self$graph <- graph
    },
    min_distance = function(dist, sptSet) {
      min <- Inf
      min_index <- -1
      for (v in 1:self$graph$V) {
        if (dist[v] < min && !sptSet[v]) {
          min <- dist[v]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, self$graph$V)
      dist[src + 1] <- 0
      sptSet <- rep(FALSE, self$graph$V)
      for (i in 1:self$graph$V) {
        u <- self$min_distance(dist, sptSet)
        sptSet[u] <- TRUE
        for (edge in self$graph$graph[[u]]) {
          v <- edge[[1]]
          weight <- edge[[2]]
          if (!sptSet[v] && dist[u] != Inf && (dist[u] + weight < dist[v])) {
            dist[v] <- dist[u] + weight
          }
        }
      }
      return(dist)
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
  sp <- ShortestPath$new(g)
  print(sp$dijkstra(0))
}

main()