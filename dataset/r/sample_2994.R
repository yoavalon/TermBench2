Node <- function(data) {
  list(data = data, neighbors = list())
}

add_neighbor <- function(node, neighbor) {
  node$neighbors <- c(node$neighbors, neighbor)
}

build_graph <- function() {
  nodes <- lapply(0:9, Node)
  for (i in 1:9) {
    add_neighbor(nodes[[i]], nodes[[i + 1]])
    add_neighbor(nodes[[i + 1]], nodes[[i]])
  }
  nodes[[1]]
}

find_shortest_path <- function(start, end, visited) {
  visited[[start$data + 1]] <- TRUE
  if (start$data == end$data) {
    return(list(end$data))
  }
  for (neighbor in start$neighbors) {
    if (!visited[[neighbor$data + 1]]) {
      path <- find_shortest_path(neighbor, end, visited)
      if (!is.null(path)) {
        return(c(start$data, path))
      }
    }
  }
  return(NULL)
}

main <- function() {
  start_node <- build_graph()
  end_node <- start_node
  visited <- vector("logical", 10)
  while (TRUE) {
    path <- find_shortest_path(start_node, end_node, visited)
    if (!is.null(path)) {
      print(path)
    } else {
      print("No path found")
    }
  }
}

main()