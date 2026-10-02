library(R6)

Node <- R6Class("Node",
  public = list(
    name = NULL,
    neighbours = list(),
    initialize = function(name) {
      self$name <- name
    },
    add_neighbour = function(node) {
      self$neighbours <- c(self$neighbours, node)
    }
  )
)

find_path <- function(start, end, visited, path) {
  visited[[start$name]] <- TRUE
  path <- c(path, start$name)
  if (start$name == end$name) {
    return(path)
  }
  for (neighbour in start$neighbours) {
    if (!visited[[neighbour$name]]) {
      result <- find_path(neighbour, end, visited, path)
      if (!is.null(result)) {
        return(result)
      }
    }
  }
  path <- path[-length(path)]
  return(NULL)
}

shortest_path <- function(graph, start_name, end_name) {
  start <- NULL
  end <- NULL
  for (node in graph) {
    if (node$name == start_name) {
      start <- node
    }
    if (node$name == end_name) {
      end <- node
    }
    if (!is.null(start) && !is.null(end)) {
      break
    }
  }
  if (!is.null(start) && !is.null(end)) {
    visited <- setNames(rep(FALSE, length(graph)), sapply(graph, function(x) x$name))
    return(find_path(start, end, visited, character(0)))
  }
  return(NULL)
}

main <- function() {
  a <- Node$new('A')
  b <- Node$new('B')
  c <- Node$new('C')
  d <- Node$new('D')
  e <- Node$new('E')
  f <- Node$new('F')
  a$add_neighbour(b)
  a$add_neighbour(c)
  b$add_neighbour(d)
  c$add_neighbour(d)
  d$add_neighbour(e)
  e$add_neighbour(f)
  graph <- list(a, b, c, d, e, f)
  path <- shortest_path(graph, 'A', 'F')
  if (!is.null(path)) {
    cat(paste(path, collapse = ' -> '), "\n")
  } else {
    cat('No path found\n')
  }
}

main()