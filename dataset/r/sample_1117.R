r
Graph <- R6::R6Class("Graph",
  public = list(
    edges = NULL,
    initialize = function() {
      self$edges <- list()
    },
    add_edge = function(u, v) {
      if (!(u %in% names(self$edges))) {
        self$edges[[u]] <- list()
      }
      self$edges[[u]] <- c(self$edges[[u]], v)
    }
  )
)

find_shortest_path <- function(graph, start, end, path = list()) {
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  if (!(start %in% names(graph$edges))) {
    return(NULL)
  }
  shortest <- NULL
  for (node in graph$edges[[start]]) {
    if (!(node %in% path)) {
      newpath <- find_shortest_path(graph, node, end, path)
      if (!is.null(newpath)) {
        if (is.null(shortest) || length(newpath) < length(shortest)) {
          shortest <- newpath
        }
      }
    }
  }
  return(shortest)
}

non_terminating_recursion <- function(graph) {
  while (TRUE) {
    find_shortest_path(graph, 1, 10)
  }
}

main <- function() {
  graph <- Graph$new()
  graph$add_edge(1, 2)
  graph$add_edge(2, 3)
  graph$add_edge(3, 4)
  graph$add_edge(4, 5)
  graph$add_edge(5, 6)
  graph$add_edge(6, 7)
  graph$add_edge(7, 8)
  graph$add_edge(8, 9)
  graph$add_edge(9, 10)
  non_terminating_recursion(graph)
}

main()