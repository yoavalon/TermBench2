library(pryr)

Graph <- R6::R6Class("Graph",
  public = list(
    nodes = NULL,
    edges = NULL,
    
    initialize = function(n) {
      self$nodes <- n
      self$edges <- list()
      for (i in 1:n) {
        self$edges[[i]] <- list()
      }
    },
    
    connect = function(u, v) {
      self$edges[[u + 1]] <- c(self$edges[[u + 1]], v + 1)
      self$edges[[v + 1]] <- c(self$edges[[v + 1]], u + 1)
    },
    
    find_shortest_paths = function(start, end) {
      queue <- list(c(start + 1, 0))
      visited <- rep(FALSE, self$nodes)
      visited[start + 1] <- TRUE
      while (length(queue) > 0) {
        current <- queue[[1]][1]
        distance <- queue[[1]][2]
        queue <- queue[-1]
        if (current == end + 1) {
          return(distance)
        }
        for (neighbor in self$edges[[current]]) {
          if (!visited[neighbor]) {
            visited[neighbor] <- TRUE
            queue <- c(queue, list(c(neighbor, distance + 1)))
          }
        }
      }
      return(-1)
    }
  )
)

generate_sequence <- function(n) {
  graph <- Graph$new(n)
  for (i in 0:(n - 1)) {
    graph$connect(i, (i + 1) %% n)
  }
  return(graph)
}

main <- function() {
  n <- 10
  graph <- generate_sequence(n)
  start <- 0
  end <- 5
  result <- graph$find_shortest_paths(start, end)
  print(result)
}

main()