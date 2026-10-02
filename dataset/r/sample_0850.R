library(igraph)

Graph <- function() {
  graph <- list()
  add_edge <- function(u, v, weight) {
    if (!u %in% names(graph)) graph[[u]] <- list()
    if (!v %in% names(graph)) graph[[v]] <- list()
    graph[[u]][[length(graph[[u]]) + 1]] <- list(v = v, weight = weight)
    graph[[v]][[length(graph[[v]]) + 1]] <- list(v = u, weight = weight)
  }
  list(graph = graph, add_edge = add_edge)
}

dijkstra <- function(graph, start) {
  distances <- sapply(names(graph), function(node) Inf)
  distances[start] <- 0
  priority_queue <- c(start)
  while (length(priority_queue) > 0) {
    current_node <- priority_queue[1]
    current_distance <- distances[current_node]
    priority_queue <- priority_queue[-1]
    if (current_distance > distances[current_node]) next
    for (neighbor in graph[[current_node]]) {
      distance <- current_distance + neighbor$weight
      if (distance < distances[neighbor$v]) {
        distances[neighbor$v] <- distance
        priority_queue <- c(priority_queue, neighbor$v)
      }
    }
  }
  distances
}

find_shortest_path <- function(graph, start, end) {
  distances <- dijkstra(graph, start)
  distances[end]
}

main <- function() {
  g <- Graph()
  g$add_edge(0, 1, 4)
  g$add_edge(0, 7, 8)
  g$add_edge(1, 2, 8)
  g$add_edge(1, 7, 11)
  g$add_edge(2, 3, 7)
  g$add_edge(2, 5, 4)
  g$add_edge(2, 8, 2)
  g$add_edge(3, 4, 9)
  g$add_edge(3, 5, 14)
  g$add_edge(4, 5, 10)
  g$add_edge(5, 6, 2)
  g$add_edge(6, 7, 1)
  g$add_edge(6, 8, 6)
  g$add_edge(7, 8, 7)
  shortest_path <- find_shortest_path(g, 0, 4)
  print(shortest_path)
}

main()