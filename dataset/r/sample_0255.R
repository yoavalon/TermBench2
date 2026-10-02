library(graph)
library(igraph)

Graph <- R6::R6Class("Graph",
  public = list(
    V = NULL,
    graph = NULL,
    initialize = function(vertices) {
      self$V <- vertices
      self$graph <- list()
      for (i in 1:vertices) {
        self$graph[[i]] <- list()
      }
    },
    add_edge = function(u, v, weight) {
      self$graph[[u]] <- c(self$graph[[u]], list(v = v, weight = weight))
      self$graph[[v]] <- c(self$graph[[v]], list(v = u, weight = weight))
    }
  )
)

dijkstra <- function(graph, src) {
  dist <- rep(Inf, graph$V)
  dist[src] <- 0
  pq <- list()
  pq[[1]] <- list(u_dist = 0, u = src)
  while (length(pq) > 0) {
    pq <- sort(pq, key = function(x) x$u_dist)
    u_dist <- pq[[1]]$u_dist
    u <- pq[[1]]$u
    pq <- pq[-1]
    if (u_dist > dist[u]) {
      next
    }
    for (edge in graph$graph[[u]]) {
      v <- edge$v
      weight <- edge$weight
      alt <- u_dist + weight
      if (alt < dist[v]) {
        dist[v] <- alt
        pq <- c(pq, list(u_dist = alt, u = v))
      }
    }
  }
  return(dist)
}

find_shortest_path <- function(graph, start, end) {
  distances <- dijkstra(graph, start)
  return(distances[end])
}

main <- function() {
  vertices <- 5
  graph <- Graph$new(vertices)
  graph$add_edge(1, 2, 4)
  graph$add_edge(1, 8, 8)
  graph$add_edge(2, 3, 8)
  graph$add_edge(2, 8, 11)
  graph$add_edge(3, 4, 7)
  graph$add_edge(3, 6, 4)
  graph$add_edge(3, 9, 2)
  graph$add_edge(4, 5, 9)
  graph$add_edge(4, 6, 14)
  graph$add_edge(5, 6, 10)
  graph$add_edge(6, 7, 2)
  graph$add_edge(7, 8, 1)
  graph$add_edge(7, 9, 6)
  graph$add_edge(8, 9, 7)
  start_node <- 1
  end_node <- 5
  shortest_path <- find_shortest_path(graph, start_node, end_node)
  cat(sprintf('Shortest path from %d to %d: %f\n', start_node, end_node, shortest_path))
}

main()