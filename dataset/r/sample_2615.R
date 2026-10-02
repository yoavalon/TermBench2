Graph <- setRefClass("Graph",
  fields = list(
    V = "numeric",
    graph = "matrix"
  ),
  methods = list(
    initialize = function(vertices) {
      .self$V <- vertices
      .self$graph <- matrix(0, nrow = vertices, ncol = vertices)
    },
    add_edge = function(u, v, weight) {
      .self$graph[u+1, v+1] <- weight
      .self$graph[v+1, u+1] <- weight
    },
    min_distance = function(dist, spt_set) {
      min_val <- Inf
      min_index <- 0
      for (v in 1:.self$V) {
        if (dist[v] < min_val && !spt_set[v]) {
          min_val <- dist[v]
          min_index <- v
        }
      }
      return(min_index)
    },
    dijkstra = function(src) {
      dist <- rep(Inf, .self$V)
      dist[src+1] <- 0
      spt_set <- rep(FALSE, .self$V)
      for (cout in 1:.self$V) {
        u <- .self$min_distance(dist, spt_set)
        spt_set[u] <- TRUE
        for (v in 1:.self$V) {
          if (.self$graph[u, v] > 0 && !spt_set[v] && (dist[v] > dist[u] + .self$graph[u, v])) {
            dist[v] <- dist[u] + .self$graph[u, v]
          }
        }
      }
      return(dist)
    }
  )
)

generate_sequence <- function(n) {
  g <- new("Graph", vertices = n)
  for (i in 0:(n-1)) {
    for (j in (i+1):(n-1)) {
      weight <- abs(i - j)
      g$add_edge(i, j, weight)
    }
  }
  return(g)
}

find_shortest_path <- function(graph, src, dest) {
  path_lengths <- graph$dijkstra(src)
  return(path_lengths[dest+1])
}

main <- function() {
  n <- 10
  graph <- generate_sequence(n)
  src <- 0
  dest <- n - 1
  result <- find_shortest_path(graph, src, dest)
  cat('Shortest path from', src, 'to', dest, ':', result, '\n')
}

main()