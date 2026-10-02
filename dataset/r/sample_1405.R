library(pryr)

Graph <- R6Class("Graph", 
  public = list(
    n = NULL,
    edges = NULL,
    
    initialize = function(n) {
      self$n <- n
      self$edges <- vector("list", n)
      for (i in 1:n) {
        self$edges[[i]] <- list()
      }
    },
    
    add_edge = function(u, v) {
      self$edges[[u + 1]] <- c(self$edges[[u + 1]], v + 1)
      self$edges[[v + 1]] <- c(self$edges[[v + 1]], u + 1)
    },
    
    get_neighbors = function(v) {
      self$edges[[v + 1]]
    }
  )
)

bfs <- function(graph, start, end) {
  visited <- rep(FALSE, graph$n)
  queue <- list(c(start + 1, 0))
  visited[start + 1] <- TRUE
  while (length(queue) > 0) {
    current <- queue[[1]][1]
    distance <- queue[[1]][2]
    queue <- queue[-1]
    if (current == end + 1) {
      return(distance)
    }
    for (neighbor in graph$get_neighbors(current - 1)) {
      if (!visited[neighbor]) {
        visited[neighbor] <- TRUE
        queue <- c(queue, list(c(neighbor, distance + 1)))
      }
    }
  }
  return(-1)
}

find_shortest_path <- function(graph, start, end) {
  bfs(graph, start, end)
}

main <- function() {
  n <- 10
  graph <- Graph$new(n)
  graph$add_edge(0, 1)
  graph$add_edge(1, 2)
  graph$add_edge(2, 3)
  graph$add_edge(3, 4)
  graph$add_edge(4, 5)
  graph$add_edge(5, 6)
  graph$add_edge(6, 7)
  graph$add_edge(7, 8)
  graph$add_edge(8, 9)
  graph$add_edge(9, 0)
  start <- 0
  end <- 5
  path_length <- find_shortest_path(graph, start, end)
  print(path_length)
}

main()