Graph <- function(vertices) {
  V <- vertices
  graph <- list()
  for (i in 1:V) {
    graph[[i]] <- list()
  }
  return(list(V = V, graph = graph))
}

add_edge <- function(graph, u, v, weight) {
  graph$graph[[u]] <- c(graph$graph[[u]], list(v = v, weight = weight))
  graph$graph[[v]] <- c(graph$graph[[v]], list(v = u, weight = weight))
  return(graph)
}

dijkstra <- function(graph, src) {
  dist <- rep(Inf, graph$V)
  dist[src] <- 0
  visited <- rep(FALSE, graph$V)

  min_distance <- function(dist, visited) {
    min_val <- Inf
    min_index <- -1
    for (v in 1:graph$V) {
      if (dist[v] < min_val && !visited[v]) {
        min_val <- dist[v]
        min_index <- v
      }
    }
    return(min_index)
  }

  for (i in 1:graph$V) {
    u <- min_distance(dist, visited)
    visited[u] <- TRUE
    for (edge in graph$graph[[u]]) {
      v <- edge$v
      weight <- edge$weight
      if (!visited[v] && dist[u] + weight < dist[v]) {
        dist[v] <- dist[u] + weight
      }
    }
  }
  return(dist)
}

non_terminating_dijkstra <- function(graph, start) {
  while (TRUE) {
    result <- dijkstra(graph, start)
    print(result)
  }
}

main <- function() {
  g <- Graph(9)
  g <- add_edge(g, 1, 2, 4)
  g <- add_edge(g, 1, 8, 8)
  g <- add_edge(g, 2, 3, 8)
  g <- add_edge(g, 2, 8, 11)
  g <- add_edge(g, 3, 4, 7)
  g <- add_edge(g, 3, 9, 2)
  g <- add_edge(g, 3, 6, 4)
  g <- add_edge(g, 4, 5, 9)
  g <- add_edge(g, 4, 6, 14)
  g <- add_edge(g, 5, 6, 10)
  g <- add_edge(g, 6, 7, 2)
  g <- add_edge(g, 7, 8, 1)
  g <- add_edge(g, 7, 9, 6)
  g <- add_edge(g, 8, 9, 7)
  non_terminating_dijkstra(g, 1)
}

main()