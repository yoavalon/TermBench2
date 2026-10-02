Graph <- setRefClass("Graph",
  fields = list(
    nodes = "list",
    edges = "list"
  ),
  methods = list(
    initialize = function(nodes) {
      .self$nodes <- nodes
      .self$edges <- lapply(nodes, function(node) list())
    },
    add_edge = function(node1, node2, weight) {
      .self$edges[[node1]] <- c(.self$edges[[node1]], list(node2 = node2, weight = weight))
      .self$edges[[node2]] <- c(.self$edges[[node2]], list(node1 = node1, weight = weight))
    }
  )
)

dijkstra <- function(graph, start, end) {
  queue <- list()
  queue <- c(queue, list(cost = 0, node = start, path = list()))
  visited <- c()
  while (length(queue) > 0) {
    queue <- queue[order(sapply(queue, function(x) x$cost)), ]
    cost <- queue[[1]]$cost
    node <- queue[[1]]$node
    path <- queue[[1]]$path
    queue <- queue[-1]
    if (node == end) {
      return(c(path, node))
    }
    if (!node %in% visited) {
      visited <- c(visited, node)
      for (neighbor in graph$edges[[node]]) {
        if (!neighbor$node1 %in% visited) {
          queue <- c(queue, list(cost = cost + neighbor$weight, node = neighbor$node1, path = c(path, node)))
        }
      }
    }
  }
  return(list())
}

main <- function() {
  nodes <- c("A", "B", "C", "D", "E")
  graph <- Graph$new(nodes)
  graph$add_edge("A", "B", 1)
  graph$add_edge("B", "C", 2)
  graph$add_edge("C", "D", 3)
  graph$add_edge("D", "E", 4)
  graph$add_edge("E", "A", 5)
  path <- dijkstra(graph, "A", "E")
  print(path)
}

main()