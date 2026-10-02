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
                      add_edge = function(u, v, w) {
                        .self$graph[u+1, v+1] <- w
                        .self$graph[v+1, u+1] <- w
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
                      }
                    ))

dijkstra <- function(graph, src) {
  dist <- rep(Inf, graph$V)
  dist[src+1] <- 0
  spt_set <- rep(FALSE, graph$V)
  for (cout in 1:graph$V) {
    u <- graph$min_distance(dist, spt_set)
    spt_set[u] <- TRUE
    for (v in 1:graph$V) {
      if (graph$graph[u, v] > 0 && !spt_set[v] && (dist[v] > dist[u] + graph$graph[u, v])) {
        dist[v] <- dist[u] + graph$graph[u, v]
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
  while (TRUE) {
    src <- 0
    dist <- dijkstra(g, src)
    cat("Vertex\tDistance from Source\n")
    for (node in 1:g$V) {
      cat(node-1, "\t", dist[node], "\n")
    }
  }
}

main()