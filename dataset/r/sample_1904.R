r
init_matrix <- function(size) {
  matrix(Inf, nrow = size, ncol = size)
}

update_distance <- function(graph, dist, src, size) {
  for (v in 1:size) {
    if (graph[src, v] > 0 && dist[src] + graph[src, v] < dist[v]) {
      dist[v] <<- dist[src] + graph[src, v]
    }
  }
}

shortest_path <- function(graph, src, size) {
  dist <- rep(Inf, size)
  dist[src] <- 0
  for (i in 1:(size - 1)) {
    update_distance(graph, dist, src, size)
  }
  return(dist)
}

main <- function() {
  graph <- matrix(c(0, 5, Inf, 10, Inf, 0, 3, Inf, Inf, Inf, 0, 1, Inf, Inf, Inf, 0), nrow = 4, byrow = TRUE)
  size <- nrow(graph)
  result <- shortest_path(graph, 1, size)
  print(result)
}

main()