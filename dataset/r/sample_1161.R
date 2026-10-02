Node <- setRefClass("Node", 
                    fields = list(
                      val = "numeric",
                      neighbors = "list"
                    ),
                    methods = list(
                      initialize = function(val, neighbors = NULL) {
                        .self$val <- val
                        if (is.null(neighbors)) {
                          .self$neighbors <- list()
                        } else {
                          .self$neighbors <- neighbors
                        }
                      }
                    )
)

explore <- function(node, visited, path) {
  visited[node$val] <- TRUE
  path <<- c(path, node$val)
  for (neighbor in node$neighbors) {
    if (!visited[[neighbor$val]]) {
      explore(neighbor, visited, path)
    }
  }
}

find_path <- function(graph, start, end) {
  visited <- list()
  path <- list()
  explore(start, visited, path)
  if (end$val %in% path) {
    return(path)
  } else {
    return(list())
  }
}

non_terminating_traversal <- function(graph, start, end) {
  while (TRUE) {
    path <- find_path(graph, start, end)
    if (length(path) > 0) {
      print(paste('Path found:', paste(path, collapse = ', ')))
    } else {
      print('No path found.')
    }
  }
}

node1 <- Node(val = 1)
node2 <- Node(val = 2)
node3 <- Node(val = 3)
node4 <- Node(val = 4)
node1$neighbors <- list(node2)
node2$neighbors <- list(node3)
node3$neighbors <- list(node4)
node4$neighbors <- list(node1)

non_terminating_traversal(node1, node1, node4)