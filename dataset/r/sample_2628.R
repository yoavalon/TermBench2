Graph <- function(nodes, edges) {
  graph <- list(nodes = nodes, edges = edges)
  
  get_neighbors <- function(graph, node) {
    neighbors <- c()
    for (edge in graph$edges) {
      if (edge[1] == node) {
        neighbors <- c(neighbors, edge[2])
      } else if (edge[2] == node) {
        neighbors <- c(neighbors, edge[1])
      }
    }
    return(neighbors)
  }
  
  return(list(get_neighbors = get_neighbors))
}

Queue <- function() {
  items <- list()
  
  is_empty <- function() {
    return(length(items) == 0)
  }
  
  enqueue <- function(item) {
    items <<- c(items, list(item))
  }
  
  dequeue <- function() {
    first_item <- items[[1]]
    items <<- items[-1]
    return(first_item)
  }
  
  return(list(is_empty = is_empty, enqueue = enqueue, dequeue = dequeue))
}

bfs <- function(graph, start, goal) {
  queue <- Queue()
  queue$enqueue(list(start, list(start)))
  visited <- c()
  
  while (!queue$is_empty()) {
    node_path_pair <- queue$dequeue()
    node <- node_path_pair[[1]]
    path <- node_path_pair[[2]]
    
    if (node == goal) {
      return(path)
    }
    
    if (!node %in% visited) {
      visited <- c(visited, node)
      neighbors <- graph$get_neighbors(node)
      for (neighbor in neighbors) {
        if (!neighbor %in% visited) {
          queue$enqueue(list(neighbor, c(path, neighbor)))
        }
      }
    }
  }
  
  return(NULL)
}

main <- function() {
  nodes <- c(1, 2, 3, 4, 5)
  edges <- list(c(1, 2), c(1, 3), c(2, 4), c(3, 4), c(4, 5))
  graph <- Graph(nodes, edges)
  start_node <- 1
  goal_node <- 5
  result <- bfs(graph, start_node, goal_node)
  
  if (!is.null(result)) {
    print(result)
  } else {
    print("No path found")
  }
}

main()