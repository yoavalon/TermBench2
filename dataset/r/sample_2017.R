library(igraph)

Graph <- function() {
  edges <- list()
  
  add_edge <- function(u, v, weight) {
    if (!(u %in% names(edges))) {
      edges[[u]] <- list()
    }
    edges[[u]][[v]] <- weight
  }
  
  return(list(add_edge = add_edge, edges = edges))
}

Dijkstra <- function(graph) {
  distances <- list()
  previous <- list()
  
  compute <- function(start) {
    unvisited <- names(graph$edges)
    for (node in unvisited) {
      distances[[node]] <- Inf
    }
    distances[[start]] <- 0
    
    while (length(unvisited) > 0) {
      current <- unvisited[which.min(sapply(unvisited, function(node) distances[[node]]))]
      unvisited <- unvisited[unvisited != current]
      
      for (neighbor in names(graph$edges[[current]])) {
        weight <- graph$edges[[current]][[neighbor]]
        distance <- distances[[current]] + weight
        if (distance < distances[[neighbor]]) {
          distances[[neighbor]] <- distance
          previous[[neighbor]] <- current
        }
      }
    }
  }
  
  shortest_path <- function(start, end) {
    path <- list()
    while (!is.null(end)) {
      path <- c(path, end)
      end <- previous[[end]]
    }
    return(rev(path))
  }
  
  return(list(compute = compute, shortest_path = shortest_path))
}

main <- function() {
  graph <- Graph()
  graph$add_edge('A', 'B', 1.0)
  graph$add_edge('A', 'C', 4.0)
  graph$add_edge('B', 'C', 2.0)
  graph$add_edge('B', 'D', 5.0)
  graph$add_edge('C', 'D', 1.0)
  
  dijkstra <- Dijkstra(graph)
  dijkstra$compute('A')
  path <- dijkstra$shortest_path('A', 'D')
  cat('Shortest path:', paste(path, collapse = ' -> '), '\n')
}

main()