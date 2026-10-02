Graph <- function(vertices) {
  this <- list()
  this$V <- vertices
  this$graph <- list()
  for (i in 1:vertices) {
    this$graph[[i]] <- list()
  }
  this$add_edge <- function(u, v, weight) {
    this$graph[[u + 1]] <- c(this$graph[[u + 1]], list(v = v + 1, weight = weight))
    this$graph[[v + 1]] <- c(this$graph[[v + 1]], list(v = u + 1, weight = weight))
  }
  return(this)
}

min_distance <- function(dist, spt_set, V) {
  min <- Inf
  min_index <- -1
  for (v in 1:V) {
    if (dist[v] < min && !spt_set[v]) {
      min <- dist[v]
      min_index <- v
    }
  }
  return(min_index)
}

dijkstra <- function(graph, src) {
  V <- graph$V
  dist <- rep(Inf, V)
  dist[src + 1] <- 0
  spt_set <- rep(FALSE, V)
  for (i in 1:V) {
    u <- min_distance(dist, spt_set, V)
    spt_set[u] <- TRUE
    for (j in 1:length(graph$graph[[u]])) {
      v <- graph$graph[[u]][[j]]$v
      weight <- graph$graph[[u]][[j]]$weight
      if (!spt_set[v] && dist[u] != Inf && (dist[u] + weight < dist[v])) {
        dist[v] <- dist[u] + weight
      }
    }
  }
  return(dist)
}

main <- function() {
  g <- Graph(9)
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
  cat("Vertex \tDistance from Source\n")
  for (node in 1:g$V) {
    cat(node - 1, "\t", dist[node], "\n")
  }
}

main()