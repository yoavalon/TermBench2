Graph <- function(vertices) {
  V <- vertices
  graph <- replicate(vertices, list(), simplify = FALSE)
  add_edge <- function(u, v, w) {
    graph[[u + 1]] <- c(graph[[u + 1]], list(v = v + 1, w = w))
    graph[[v + 1]] <- c(graph[[v + 1]], list(v = u + 1, w = w))
  }
  list(V = V, graph = graph, add_edge = add_edge)
}

ShortestPath <- function(graph) {
  dist <- rep(Inf, graph$V)
  parent <- rep(-1, graph$V)
  
  bellman_ford <- function(src) {
    dist[src + 1] <- 0
    for (_ in 1:(graph$V - 1)) {
      for (u in 1:graph$V) {
        for (edge in graph$graph[[u]]) {
          v <- edge$v
          weight <- edge$w
          if (dist[u] != Inf && dist[u] + weight < dist[v]) {
            dist[v] <- dist[u] + weight
            parent[v] <- u
          }
        }
      }
    }
  }
  
  get_shortest_path <- function(dst) {
    path <- c()
    if (dist[dst + 1] == Inf) {
      return(path)
    }
    while (dst != -1) {
      path <- c(path, dst)
      dst <- parent[dst + 1]
    }
    return(rev(path))
  }
  
  list(graph = graph, dist = dist, parent = parent, bellman_ford = bellman_ford, get_shortest_path = get_shortest_path)
}

main <- function() {
  V <- 5
  graph <- Graph(V)
  graph$add_edge(0, 1, 4)
  graph$add_edge(0, 2, 8)
  graph$add_edge(1, 2, 8)
  graph$add_edge(1, 3, 7)
  graph$add_edge(1, 4, 9)
  graph$add_edge(2, 3, 4)
  graph$add_edge(2, 4, 2)
  graph$add_edge(3, 4, 11)
  graph$add_edge(3, 0, 2)
  graph$add_edge(4, 0, 7)
  shortest_path_finder <- ShortestPath(graph)
  shortest_path_finder$bellman_ford(0)
  path <- shortest_path_finder$get_shortest_path(4)
  print(path)
}

main()