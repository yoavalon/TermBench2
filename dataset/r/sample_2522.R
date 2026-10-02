bfs <- function(graph, start, goal) {
  queue <- list(c(start, start))
  while (length(queue) > 0) {
    item <- queue[[1]]
    vertex <- item[1]
    path <- item[2]
    queue <- queue[-1]
    for (next in setdiff(graph[[vertex]], path)) {
      if (next == goal) {
        return(c(path, next))
      } else {
        queue <- c(queue, list(c(next, c(path, next))))
      }
    }
  }
  return(NULL)
}

find_path <- function(graph, start, goal) {
  path <- bfs(graph, start, goal)
  if (is.null(path)) {
    return(list())
  } else {
    return(path)
  }
}

main <- function() {
  graph <- list(A = c("B", "C"), B = c("D", "E"), C = c("F"), D = c(), E = c("F"), F = c())
  start_node <- "A"
  goal_node <- "F"
  result <- find_path(graph, start_node, goal_node)
  print(result)
}

main()