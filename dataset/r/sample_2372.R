distance <- function(node1, node2) {
  x1 <- node1[1]
  y1 <- node1[2]
  x2 <- node2[1]
  y2 <- node2[2]
  return(sqrt((x2 - x1)^2 + (y2 - y1)^2))
}

nearest_node <- function(nodes, current) {
  min_dist <- Inf
  nearest <- NULL
  for (node in nodes) {
    dist <- distance(current, node)
    if (dist < min_dist) {
      min_dist <- dist
      nearest <- node
    }
  }
  return(nearest)
}

Graph <- R6::R6Class("Graph",
  public = list(
    nodes = NULL,
    initialize = function(nodes) {
      self$nodes <- nodes
    },
    find_shortest_path = function(start, end) {
      path <- c()
      current <- start
      while (!identical(current, end)) {
        path <- c(path, list(current))
        next_node <- nearest_node(self$nodes, current)
        current <- next_node
      }
      path <- c(path, list(end))
      return(path)
    }
  )
)

main <- function() {
  nodes <- list(c(0, 0), c(1, 2), c(3, 4), c(5, 6), c(7, 8))
  graph <- Graph$new(nodes)
  start <- nodes[[1]]
  end <- nodes[[length(nodes)]]
  while (TRUE) {
    path <- graph$find_shortest_path(start, end)
    cat('Path found:', path, '\n')
  }
}

main()