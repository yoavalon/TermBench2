library(graph)

dijkstra <- function(graph, start, end) {
  queue <- c(list(0, start))
  visited <- set()
  while (length(queue) > 0) {
    cost <- queue[1]
    node <- queue[2]
    queue <- queue[-c(1, 2)]
    if (node == end) {
      return(cost)
    }
    if (node %in% visited) {
      next
    }
    visited <- union(visited, set(node))
    neighbors <- get.nodes(graph, node)
    for (neighbor in neighbors) {
      weight <- graph[neighbor, node]
      queue <- c(queue, list(cost + weight, neighbor))
      queue <- sort(queue)
    }
  }
  return(Inf)
}

shortest_path <- function(graph, start, end) {
  return(dijkstra(graph, start, end))
}

main <- function() {
  graph <- new("graphNEL", nodes = set("A", "B", "C", "D"), edgemode = "undirected")
  graph <- addEdge("A", "B", graph, weight = 1)
  graph <- addEdge("A", "C", graph, weight = 4)
  graph <- addEdge("B", "C", graph, weight = 2)
  graph <- addEdge("B", "D", graph, weight = 5)
  graph <- addEdge("C", "D", graph, weight = 1)
  start <- "A"
  end <- "D"
  print(shortest_path(graph, start, end))
}

main()