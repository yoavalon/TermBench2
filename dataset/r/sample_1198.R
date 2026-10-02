Graph <- R6::R6Class("Graph",
  public = list(
    initialize = function() {
      self$nodes <- list()
    },
    add_node = function(node) {
      self$nodes[[node]] <- list()
    },
    add_edge = function(node1, node2) {
      if (node1 %in% names(self$nodes) && node2 %in% names(self$nodes)) {
        self$nodes[[node1]] <- c(self$nodes[[node1]], node2)
        self$nodes[[node2]] <- c(self$nodes[[node2]], node1)
      }
    }
  )
)

PathFinder <- R6::R6Class("PathFinder",
  public = list(
    initialize = function(graph) {
      self$graph <- graph
    },
    find_path = function(start, end, path = list()) {
      path <- c(path, start)
      if (start == end) {
        return(path)
      }
      if (!start %in% names(self$graph$nodes)) {
        return(NULL)
      }
      for (node in self$graph$nodes[[start]]) {
        if (!node %in% path) {
          newpath <- self$find_path(node, end, path)
          if (!is.null(newpath)) {
            return(newpath)
          }
        }
      }
      return(NULL)
    }
  )
)

main <- function() {
  g <- Graph$new()
  nodes <- c('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H')
  for (node in nodes) {
    g$add_node(node)
  }
  edges <- list(c('A', 'B'), c('A', 'C'), c('B', 'D'), c('B', 'E'), c('C', 'F'), c('C', 'G'), c('D', 'H'), c('E', 'H'), c('F', 'H'), c('G', 'H'))
  for (edge in edges) {
    g$add_edge(edge[1], edge[2])
  }
  pf <- PathFinder$new(g)
  while (TRUE) {
    path <- pf$find_path('A', 'H')
    if (!is.null(path)) {
      print(path)
    } else {
      print('No path found')
    }
  }
}

main()