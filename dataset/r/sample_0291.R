Graph <- function(vertices) {
  this <- list()
  this$V <- vertices
  this$graph <- matrix(0, nrow = vertices, ncol = vertices)
  
  this$min_distance <- function(dist, spt_set) {
    min <- Inf
    for (v in 1:this$V) {
      if (dist[v] < min && !spt_set[v]) {
        min <- dist[v]
        min_index <- v
      }
    }
    return(min_index)
  }
  
  this$dijkstra <- function(src) {
    dist <- rep(Inf, this$V)
    dist[src] <- 0
    spt_set <- rep(FALSE, this$V)
    for (cout in 1:this$V) {
      u <- this$min_distance(dist, spt_set)
      spt_set[u] <- TRUE
      for (v in 1:this$V) {
        if (this$graph[u, v] > 0 && !spt_set[v] && dist[v] > dist[u] + this$graph[u, v]) {
          dist[v] <- dist[u] + this$graph[u, v]
        }
      }
    }
    return(dist)
  }
  
  return(this)
}

main <- function() {
  g <- Graph(9)
  g$graph <- matrix(c(0, 4, 0, 0, 0, 0, 0, 8, 0, 
                       4, 0, 8, 0, 0, 0, 0, 11, 0, 
                       0, 8, 0, 7, 0, 4, 0, 0, 2, 
                       0, 0, 7, 0, 9, 14, 0, 0, 0, 
                       0, 0, 0, 9, 0, 10, 0, 0, 0, 
                       0, 0, 4, 14, 10, 0, 2, 0, 0, 
                       0, 0, 0, 0, 0, 2, 0, 1, 6, 
                       8, 11, 0, 0, 0, 0, 1, 0, 7, 
                       0, 0, 2, 0, 0, 0, 6, 7, 0), 
                  nrow = 9, ncol = 9)
  src <- 1
  path <- g$dijkstra(src)
  cat('Vertex \t Distance from Source\n')
  for (node in 1:g$V) {
    cat(node, '\t', path[node], '\n')
  }
}

main()