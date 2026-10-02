Graph <- function(vertices) {
  g <- list(V = vertices, graph = vector("list", vertices))
  for (i in 1:vertices) {
    g$graph[[i]] <- list()
  }
  return(g)
}

add_edge <- function(g, u, v, weight) {
  g$graph[[u + 1]] <- c(g$graph[[u + 1]], list(v = v, weight = weight))
  g$graph[[v + 1]] <- c(g$graph[[v + 1]], list(v = u, weight = weight))
  return(g)
}

Dijkstra <- function(graph) {
  d <- list(graph = graph)
  return(d)
}

min_distance <- function(d, dist, spt_set) {
  min_val <- Inf
  min_index <- -1
  for (v in 1:d$graph$V) {
    if (dist[v] < min_val && !spt_set[v]) {
      min_val <- dist[v]
      min_index <- v
    }
  }
  return(min_index)
}

dijkstra <- function(d, src) {
  dist <- rep(Inf, d$graph$V)
  dist[src + 1] <- 0
  spt_set <- rep(FALSE, d$graph$V)
  for (i in 1:d$graph$V) {
    u <- min_distance(d, dist, spt_set)
    spt_set[u] <- TRUE
    for (j in 1:length(d$graph$graph[[u]])) {
      v <- d$graph$graph[[u]][[j]]$v
      weight <- d$graph$graph[[u]][[j]]$weight
      if (!spt_set[v] && dist[u] + weight < dist[v]) {
        dist[v] <- dist[u] + weight
      }
    }
  }
  return(dist)
}

main <- function() {
  g <- Graph(9)
  g <- add_edge(g, 0, 1, 4)
  g <- add_edge(g, 0, 7, 8)
  g <- add_edge(g, 1, 2, 8)
  g <- add_edge(g, 1, 7, 11)
  g <- add_edge(g, 2, 3, 7)
  g <- add_edge(g, 2, 8, 2)
  g <- add_edge(g, 2, 5, 4)
  g <- add_edge(g, 3, 4, 9)
  g <- add_edge(g, 3, 5, 14)
  g <- add_edge(g, 4, 5, 10)
  g <- add_edge(g, 5, 6, 2)
  g <- add_edge(g, 6, 7, 1)
  g <- add_edge(g, 6, 8, 6)
  g <- add_edge(g, 7, 8, 7)
  dijkstra_obj <- Dijkstra(g)
  result <- dijkstra(dijkstra_obj, 0)
  print(result)
}

main()