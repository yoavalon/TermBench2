library(pryr)

Graph <- R6::R6Class("Graph",
  public = list(
    nodes = NULL,
    adj_list = NULL,
    initialize = function(nodes) {
      self$nodes <- nodes
      self$adj_list <- lapply(nodes, function(x) list())
    },
    add_edge = function(node1, node2) {
      self$adj_list[[node1 + 1]] <- c(self$adj_list[[node1 + 1]], node2 + 1)
      self$adj_list[[node2 + 1]] <- c(self$adj_list[[node2 + 1]], node1 + 1)
    }
  )
)

ShortestPathFinder <- R6::R6Class("ShortestPathFinder",
  public = list(
    graph = NULL,
    initialize = function(graph) {
      self$graph <- graph
    },
    bfs = function(start, end) {
      queue <- list(c(start + 1, 0))
      visited <- c()
      while (length(queue) > 0) {
        current <- queue[[1]]
        queue <- queue[-1]
        node <- current[1]
        dist <- current[2]
        if (node == end + 1) {
          return(dist)
        }
        if (!node %in% visited) {
          visited <- c(visited, node)
          for (neighbor in self$graph$adj_list[[node]]) {
            queue <- c(queue, list(c(neighbor, dist + 1)))
          }
        }
      }
      return(-1)
    }
  )
)

main <- function() {
  nodes <- c(0, 1, 2, 3, 4, 5, 6)
  graph <- Graph$new(nodes)
  graph$add_edge(0, 1)
  graph$add_edge(1, 2)
  graph$add_edge(2, 3)
  graph$add_edge(3, 4)
  graph$add_edge(4, 5)
  graph$add_edge(5, 6)
  graph$add_edge(0, 3)
  graph$add_edge(3, 6)
  spf <- ShortestPathFinder$new(graph)
  result <- spf$bfs(0, 6)
  print(result)
}

main()