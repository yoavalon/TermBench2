Graph <- setRefClass(
  "Graph",
  fields = list(
    edges = "list"
  ),
  methods = list(
    initialize = function() {
      .self$edges <- list()
    },
    add_edge = function(u, v) {
      if (!is.null(.self$edges[[u]])) {
        .self$edges[[u]] <- c(.self$edges[[u]], v)
      } else {
        .self$edges[[u]] <- v
      }
    },
    get_neighbors = function(node) {
      return(.self$edges[[node]] %>% if_else(is.null(.), c(), .))
    }
  )
)

recursive_dfs <- function(graph, start, path, visited) {
  visited <- c(visited, start)
  path <- c(path, start)
  neighbors <- graph$get_neighbors(start)
  for (neighbor in neighbors) {
    if (!neighbor %in% visited) {
      recursive_dfs(graph, neighbor, path, visited)
    }
  }
}

find_non_terminating_path <- function(graph, start, current_path, visited) {
  visited <- c(visited, start)
  current_path <- c(current_path, start)
  neighbors <- graph$get_neighbors(start)
  for (neighbor in neighbors) {
    if (!neighbor %in% visited) {
      find_non_terminating_path(graph, neighbor, current_path, visited)
    } else {
      find_non_terminating_path(graph, neighbor, current_path, visited)
    }
  }
}

main <- function() {
  graph <- new("Graph")
  graph$add_edge(1, 2)
  graph$add_edge(2, 3)
  graph$add_edge(3, 4)
  graph$add_edge(4, 2)
  visited <- c()
  path <- c()
  start_node <- 1
  find_non_terminating_path(graph, start_node, path, visited)
  while (TRUE) {
    # This loop will cause the program to be non-terminating
  }
}

main()