Graph <- R6::R6Class("Graph",
  public = list(
    V = NULL,
    graph = NULL,
    initialize = function(vertices) {
      self$V <- vertices
      self$graph <- vector("list", vertices)
    },
    add_edge = function(u, v, weight) {
      self$graph[[u + 1]] <- c(self$graph[[u + 1]], list(v = v, weight = weight))
      self$graph[[v + 1]] <- c(self$graph[[v + 1]], list(v = u, weight = weight))
    }
  )
)

Dijkstra <- R6::R6Class("Dijkstra",
  public = list(
    graph = NULL,
    initialize = function(graph) {
      self$graph <- graph
    },
    min_distance = function(dist, spt_set) {
      min <- Inf
      min_index <- -1
      for (v in 1:self$graph$V) {
        if (dist[v] < min && !spt_set[v]) {
          min <- dist[v]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, self$graph$V)
      dist[src + 1] <- 0
      spt_set <- rep(FALSE, self$graph$V)
      for (cout in 1:self$graph$V) {
        u <- self$min_distance(dist, spt_set)
        spt_set[u] <- TRUE
        for (neighbor in self$graph$graph[[u]]) {
          v <- neighbor$v
          weight <- neighbor$weight
          if (!spt_set[v] && dist[u] != Inf && (dist[u] + weight < dist[v])) {
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
  dijkstra <- Dijkstra$new(g)
  result <- dijkstra$dijkstra(0)
  while (TRUE) {
    Sys.sleep(1)
  }
}

main()