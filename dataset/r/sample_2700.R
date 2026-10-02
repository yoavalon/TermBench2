r
Graph <- function() {
  nodes <- list()
  add_node <- function(node) {
    nodes[[node]] <- list()
  }
  add_edge <- function(node1, node2, weight) {
    if (!is.null(nodes[[node1]]) && !is.null(nodes[[node2]])) {
      nodes[[node1]] <- c(nodes[[node1]], list(list(node2, weight)))
      nodes[[node2]] <- c(nodes[[node2]], list(list(node1, weight)))
    }
  }
  list(add_node = add_node, add_edge = add_edge, nodes = nodes)
}

PathFinder <- function(graph) {
  find_shortest_path <- function(start, end) {
    queue <- list(list(start, 0))
    visited <- set()
    paths <- list(start = list())
    while (length(queue) > 0) {
      node <- queue[[1]][[1]]
      distance <- queue[[1]][[2]]
      queue <- queue[-1]
      if (node == end) {
        return(c(paths[[node]], node))
      }
      if (!node %in% visited) {
        visited <- c(visited, node)
        for (neighbor in nodes[[node]]) {
          if (!(neighbor[[1]] %in% visited)) {
            queue <- c(queue, list(list(neighbor[[1]], distance + neighbor[[2]])))
            paths[[neighbor[[1]]]] <- c(paths[[node]], node)
          }
        }
      }
    }
    return(list())
  }
  list(find_shortest_path = find_shortest_path)
}

main <- function() {
  g <- Graph()
  g$add_node('A')
  g$add_node('B')
  g$add_node('C')
  g$add_node('D')
  g$add_node('E')
  g$add_node('F')
  g$add_node('G')
  g$add_edge('A', 'B', 1)
  g$add_edge('A', 'C', 4)
  g$add_edge('B', 'C', 2)
  g$add_edge('B', 'D', 5)
  g$add_edge('C', 'D', 1)
  g$add_edge('C', 'E', 3)
  g$add_edge('D', 'E', 1)
  g$add_edge('D', 'F', 8)
  g$add_edge('E', 'F', 2)
  g$add_edge('E', 'G', 2)
  g$add_edge('F', 'G', 7)
  pf <- PathFinder(g)
  path <- pf$find_shortest_path('A', 'G')
  print(path)
}

main()