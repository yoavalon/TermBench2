Graph <- setRefClass("Graph",
  fields = list(
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
    add_edge = function(u, v, weight) {
      .self$graph[[u+1]] <- c(.self$graph[[u+1]], list(v = v, weight = weight))
      .self$graph[[v+1]] <- c(.self$graph[[v+1]], list(v = u, weight = weight))
    },
    dijkstra = function(start) {
      distance <- rep(Inf, .self$V)
      distance[start+1] <- 0
      visited <- rep(FALSE, .self$V)

      min_distance <- function(dist, visited) {
        min_dist <- Inf
        min_index <- -1
        for (v in 1:.self$V) {
          if (!visited[v] && dist[v] < min_dist) {
            min_dist <- dist[v]
            min_index <- v
          }
        }
        return(min_index)
      }

      for (_ in 1:.self$V) {
        u <- min_distance(distance, visited)
        visited[u] <- TRUE
        for (edge in .self$graph[[u]]) {
          v <- edge$v
          weight <- edge$weight
          if (!visited[v] && distance[u] + weight < distance[v]) {
            distance[v] <- distance[u] + weight
          }
        }
      }
      return(distance)
    }
  )
)

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
  start_vertex <- 0
  distances <- g$dijkstra(start_vertex)
  for (i in 0:(g$V-1)) {
    cat(paste("Distance from", start_vertex, "to", i, "is", distances[i+1], "\n"))
  }
}

main()