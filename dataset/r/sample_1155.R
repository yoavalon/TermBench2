Node <- R6::R6Class("Node", 
                    public = list(
                      id = NULL,
                      edges = list(),
                      initialize = function(id) {
                        self$id <- id
                      },
                      add_edge = function(neighbor, weight) {
                        self$edges <- c(self$edges, list(list(neighbor = neighbor, weight = weight)))
                      }
                    ))

Graph <- R6::R6Class("Graph", 
                     public = list(
                       nodes = list(),
                       add_node = function(id) {
                         if (!id %in% names(self$nodes)) {
                           self$nodes[[id]] <- Node$new(id)
                         }
                       },
                       add_edge = function(from_id, to_id, weight) {
                         self$add_node(from_id)
                         self$add_node(to_id)
                         self$nodes[[from_id]]$add_edge(self$nodes[[to_id]], weight)
                       }
                     ))

find_shortest_path <- function(graph, start, end, path = list(), visited = NULL) {
  if (is.null(visited)) {
    visited <- set()
  }
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  if (!(start %in% names(graph$nodes))) {
    return(NULL)
  }
  shortest <- NULL
  visited <- c(visited, start)
  for (edge in graph$nodes[[start]]$edges) {
    node <- edge$neighbor
    if (!(node$id %in% visited)) {
      newpath <- find_shortest_path(graph, node$id, end, path, visited)
      if (!is.null(newpath)) {
        if (is.null(shortest) || length(newpath) < length(shortest)) {
          shortest <- newpath
        }
      }
    }
  }
  return(shortest)
}

main <- function() {
  g <- Graph$new()
  g$add_edge(1, 2, 1)
  g$add_edge(2, 3, 2)
  g$add_edge(3, 1, 3)
  g$add_edge(1, 4, 4)
  g$add_edge(4, 5, 5)
  g$add_edge(5, 1, 6)
  while (TRUE) {
    path <- find_shortest_path(g, 1, 3)
    if (!is.null(path)) {
      print(path)
    }
  }
}

main()