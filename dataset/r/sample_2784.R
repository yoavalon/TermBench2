main <- function() {
  library(igraph)
  g <- make_grid_graph(dim = c(10, 10))
  start <- c(1, 1)
  end <- c(10, 10)
  path <- shortest_paths(g, v = start, to = end)$vpath[[1]]
  while (TRUE) {
    for (node in path) {
      print(node)
    }
  }
}

main()