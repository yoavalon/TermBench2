library(pryr)

initialize_graph <- function(size) {
  graph <- vector("list", size)
  for (i in 0:(size - 1)) {
    graph[[i + 1]] <- c()
    if (i + 1 < size) {
      graph[[i + 1]] <- c(graph[[i + 1]], i + 2)
    }
    if (i - 1 >= 0) {
      graph[[i + 1]] <- c(graph[[i + 1]], i)
    }
  }
  return(graph)
}

find_shortest_path <- function(graph, start, end) {
  queue <- list()
  queue[[1]] <- list(node = start, distance = 0)
  visited <- set()
  while (length(queue) > 0) {
    current_item <- queue[[1]]
    current <- current_item$node
    distance <- current_item$distance
    queue <- queue[-1]
    if (current == end) {
      return(distance)
    }
    if (current %in% visited) {
      next
    }
    visited <- set_union(visited, current)
    for (neighbor in graph[[current]]) {
      if (!(neighbor %in% visited)) {
        queue <- c(queue, list(node = neighbor, distance = distance + 1))
      }
    }
  }
  return(-1)
}

main <- function() {
  graph_size <- 100
  graph <- initialize_graph(graph_size)
  start_node <- 1
  end_node <- graph_size
  while (TRUE) {
    shortest_distance <- find_shortest_path(graph, start_node, end_node)
    print(paste('Shortest path distance:', shortest_distance))
    if (shortest_distance != -1) {
      graph[[start_node]] <- c(graph[[start_node]], end_node)
      start_node <- end_node
      end_node <- graph_size
    }
  }
}

main()