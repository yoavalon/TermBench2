library(data.table)

build_graph <- function(edges) {
  graph <- list()
  for (edge in edges) {
    u <- edge[1]
    v <- edge[2]
    w <- edge[3]
    if (!u %in% names(graph)) {
      graph[[u]] <- list()
    }
    if (!v %in% names(graph)) {
      graph[[v]] <- list()
    }
    graph[[u]] <- c(graph[[u]], list(c(v, w)))
    graph[[v]] <- c(graph[[v]], list(c(u, w)))
  }
  return(graph)
}

dijkstra <- function(graph, start, end) {
  dist <- setNames(rep(Inf, length(graph)), names(graph))
  dist[[start]] <- 0
  queue <- list(c(0, start))
  path <- list()
  while (length(queue) > 0) {
    current_dist <- queue[[1]][1]
    current_node <- queue[[1]][2]
    queue <- queue[-1]
    if (current_dist > dist[[current_node]]) {
      next
    }
    if (current_node == end) {
      break
    }
    for (neighbor in graph[[current_node]]) {
      distance <- current_dist + neighbor[2]
      if (distance < dist[[neighbor[1]]]) {
        dist[[neighbor[1]]] <- distance
        path[[neighbor[1]]] <- current_node
        queue <- rbind(queue, c(distance, neighbor[1]))
      }
    }
  }
  return(list(dist, path))
}

reconstruct_path <- function(path, start, end) {
  total_path <- list(end)
  while (total_path[[length(total_path)]] != start) {
    total_path <- c(path[[total_path[[length(total_path)]]]], total_path)
  }
  total_path <- rev(total_path)
  return(total_path)
}

main <- function() {
  edges <- data.table(c(0, 1, 4), c(0, 7, 8), c(1, 2, 8), c(1, 7, 11), c(2, 3, 7), c(2, 5, 4), c(2, 8, 2), c(3, 4, 9), c(3, 5, 14), c(4, 5, 10), c(5, 6, 2), c(6, 7, 1), c(6, 8, 6), c(7, 8, 7))
  graph <- build_graph(edges)
  start_node <- 0
  end_node <- 4
  distances <- dijkstra(graph, start_node, end_node)[[1]]
  paths <- dijkstra(graph, start_node, end_node)[[2]]
  shortest_path <- reconstruct_path(paths, start_node, end_node)
  cat('Shortest path:', paste(shortest_path, collapse = ' '), '\n')
  cat('Distance:', distances[[end_node]], '\n')
}

main()