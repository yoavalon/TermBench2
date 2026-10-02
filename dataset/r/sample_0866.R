Graph <- setRefClass("Graph",
  fields = list(
    v = "numeric",
    graph = "matrix"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$v <- vertices
      .self$graph <- matrix(0, vertices, vertices)
    },
    add_edge = function(u, v, weight) {
      .self$graph[u + 1, v + 1] <- weight
      .self$graph[v + 1, u + 1] <- weight
    }
  )
)

min_distance <- function(dist, visited, v) {
  min_val <- Inf
  min_index <- -1
  for (i in 1:v) {
    if (dist[i] < min_val && !visited[i]) {
      min_val <- dist[i]
      min_index <- i
    }
  }
  return(min_index)
}

dijkstra <- function(graph, src, v) {
  dist <- rep(Inf, v)
  dist[src + 1] <- 0
  visited <- rep(FALSE, v)
  for (i in 1:v) {
    u <- min_distance(dist, visited, v)
    visited[u] <- TRUE
    for (j in 1:v) {
      if (graph[u, j] > 0 && !visited[j] && (dist[u] + graph[u, j] < dist[j])) {
        dist[j] <- dist[u] + graph[u, j]
      }
    }
  }
  return(dist)
}

main <- function() {
  v <- 9
  g <- new("Graph", vertices = v)
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
  dist <- dijkstra(g$graph, 0, v)
  for (node in 1:v) {
    cat("Distance to", node - 1, ":", dist[node], "\n")
  }
}

main()