Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "matrix"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$V <- vertices
      .self$graph <- matrix(0, vertices, vertices)
    },
    add_edge = function(u, v, weight) {
      .self$graph[u + 1, v + 1] <- weight
      .self$graph[v + 1, u + 1] <- weight
    }
  )
)

dijkstra <- function(graph, src, dist, visited, path) {
  if (all(visited)) {
    return()
  }
  u <- which(!visited)[which.min(dist[!visited])]
  visited[u] <<- TRUE
  for (v in 1:graph$V) {
    if (!visited[v] && graph$graph[u, v] != 0) {
      if (dist[u] + graph$graph[u, v] < dist[v]) {
        dist[v] <<- dist[u] + graph$graph[u, v]
        path[v] <<- u
      }
    }
  }
  dijkstra(graph, src, dist, visited, path)
}

find_shortest_path <- function(graph, src, dest) {
  dist <- rep(Inf, graph$V)
  dist[src + 1] <- 0
  visited <- rep(FALSE, graph$V)
  path <- rep(-1, graph$V)
  dijkstra(graph, src, dist, visited, path)
  if (dist[dest + 1] == Inf) {
    return(c())
  }
  result <- c()
  while (dest + 1 != -1) {
    result <- c(dest + 1, result)
    dest <- path[dest + 1]
  }
  return(result)
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
  print(find_shortest_path(g, 0, 4))
}

main()