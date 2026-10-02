Graph <- function(vertices) {
  this <- list(
    V = vertices,
    graph = matrix(0, nrow = vertices, ncol = vertices)
  )
  
  add_edge <- function(u, v, weight) {
    this$graph[u + 1, v + 1] <- weight
    this$graph[v + 1, u + 1] <- weight
  }
  
  dijkstra <- function(graph, src) {
    dist <- rep(Inf, graph$V)
    dist[src + 1] <- 0
    sptSet <- rep(FALSE, graph$V)
    
    for (i in 1:graph$V) {
      u <- min_distance(dist, sptSet, graph$V)
      sptSet[u + 1] <- TRUE
      
      for (v in 1:graph$V) {
        if (!sptSet[v + 1] && graph$graph[u + 1, v + 1] != 0 && dist[u + 1] != Inf && (dist[u + 1] + graph$graph[u + 1, v + 1] < dist[v + 1])) {
          dist[v + 1] <- dist[u + 1] + graph$graph[u + 1, v + 1]
        }
      }
    }
    return(dist)
  }
  
  min_distance <- function(dist, sptSet, V) {
    min_val <- Inf
    min_index <- -1
    
    for (v in 1:V) {
      if (dist[v] < min_val && !sptSet[v]) {
        min_val <- dist[v]
        min_index <- v - 1
      }
    }
    return(min_index)
  }
  
  return(list(
    add_edge = add_edge,
    dijkstra = dijkstra
  ))
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
  
  dist <- g$dijkstra(g, 0)
  
  for (node in 0:(g$V - 1)) {
    cat(sprintf("Distance from 0 to %d is %f\n", node, dist[node + 1]))
  }
}

main()