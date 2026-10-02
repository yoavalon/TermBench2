Graph <- setRefClass("Graph",
                    fields = list(V = "numeric", graph = "matrix"),
                    methods = list(
                      initialize = function(vertices) {
                        .self$V <- vertices
                        .self$graph <- matrix(0, vertices, vertices)
                      },
                      add_edge = function(u, v, weight) {
                        .self$graph[u + 1, v + 1] <- weight
                        .self$graph[v + 1, u + 1] <- weight
                      },
                      min_distance = function(dist, spt_set) {
                        min <- Inf
                        min_index <- -1
                        for (v in 1:.self$V) {
                          if (dist[v] < min && !spt_set[v]) {
                            min <- dist[v]
                            min_index <- v
                          }
                        }
                        return(min_index)
                      },
                      dijkstra = function(src) {
                        dist <- rep(Inf, .self$V)
                        dist[src + 1] <- 0
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
                    ))

SequenceGenerator <- setRefClass("SequenceGenerator",
                                fields = list(graph = "Graph"),
                                methods = list(
                                  initialize = function(graph) {
                                    .self$graph <- graph
                                  },
                                  generate_sequence = function(start_vertex) {
                                    sequence <- c()
                                    while (TRUE) {
                                      distances <- .self$graph$dijkstra(start_vertex)
                                      next_vertex <- which.min(distances) - 1
                                      sequence <- c(sequence, next_vertex)
                                      start_vertex <- next_vertex
                                    }
                                  }
                                ))

main <- function() {
  vertices <- 5
  graph <- Graph$new(vertices)
  graph$add_edge(0, 1, 4)
  graph$add_edge(0, 3, 7)
  graph$add_edge(1, 2, 1)
  graph$add_edge(1, 3, 2)
  graph$add_edge(1, 4, 10)
  graph$add_edge(2, 3, 5)
  graph$add_edge(3, 4, 3)
  graph$add_edge(2, 4, 8)
  sequence_generator <- SequenceGenerator$new(graph)
  sequence <- sequence_generator$generate_sequence(0)
  for (vertex in sequence) {
    cat(vertex, "\n")
  }
}

main()