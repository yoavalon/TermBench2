Graph <- setRefClass("Graph",
  fields = list(nodes = "list"),
  methods = list(
    initialize = function() {
      .self$nodes <- list()
    },
    add_node = function(node) {
      if (!node %in% names(.self$nodes)) {
        .self$nodes[[node]] <- list()
      }
    },
    add_edge = function(node1, node2, weight) {
      if (node1 %in% names(.self$nodes) && node2 %in% names(.self$nodes)) {
        .self$nodes[[node1]] <- c(.self$nodes[[node1]], list(list(node2, weight)))
        .self$nodes[[node2]] <- c(.self$nodes[[node2]], list(list(node1, weight)))
      }
    }
  )
)

find_neighbors <- function(graph, node) {
  if (node %in% names(graph$nodes)) {
    return(graph$nodes[[node]])
  }
  return(list())
}

shortest_path <- function(graph, start, end, path = list()) {
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  shortest <- NULL
  neighbors <- find_neighbors(graph, start)
  for (neighbor in neighbors) {
    if (!neighbor[[1]] %in% path) {
      new_path <- shortest_path(graph, neighbor[[1]], end, path)
      if (!is.null(new_path)) {
        if (is.null(shortest) || length(new_path) < length(shortest)) {
          shortest <- new_path
        }
      }
    }
  }
  return(shortest)
}

main <- function() {
  g <- new("Graph")
  nodes <- c('A', 'B', 'C', 'D', 'E', 'F')
  for (node in nodes) {
    g$add_node(node)
  }
  edges <- list(c('A', 'B', 1), c('A', 'C', 4), c('B', 'C', 2), c('B', 'D', 5), c('C', 'D', 1), c('D', 'E', 3), c('E', 'F', 2))
  for (edge in edges) {
    g$add_edge(edge[1], edge[2], edge[3])
  }
  print(shortest_path(g, 'A', 'F'))
}

main()