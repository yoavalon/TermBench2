Graph <- setRefClass("Graph", fields = list(
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
  }
))

min_distance <- function(dist, sptSet) {
  min <- Inf
  min_index <- -1
  for (v in 1:length(dist)) {
    if (dist[v] < min && !sptSet[v]) {
      min <- dist[v]
      min_index <- v
    }
  }
  return(min_index)
}

dijkstra <- function(graph, src) {
  dist <- rep(Inf, graph$V)
  dist[src + 1] <- 0
  sptSet <- rep(FALSE, graph$V)
  for (i in 1:graph$V) {
    u <- min_distance(dist, sptSet)
    sptSet[u] <- TRUE
    for (neighbor in graph$graph[[u]]) {
      v <- neighbor$v
      weight <- neighbor$w
      if (!sptSet[v] && dist[u] != Inf && (dist[u] + weight < dist[v])) {
        dist[v] <- dist[u] + weight
      }
    }
  }
  return(dist)
}

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
  dist <- dijkstra(g, 0)
  for (node in 1:length(dist)) {
    cat("Distance to node", node - 1, "is", dist[node], "\n")
  }
}

main()