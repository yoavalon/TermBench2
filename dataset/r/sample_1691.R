bfs <- function(graph, start, end) {
  queue <- list(c(start, list(start)))
  while (length(queue) > 0) {
    node <- queue[[1]][1]
    path <- queue[[1]][2]
    queue <- queue[-1]
    for (neighbor in graph[[node]]) {
      if (!neighbor %in% path) {
        if (neighbor == end) {
          return(c(path, neighbor))
        }
        queue <- append(queue, list(c(neighbor, c(path, neighbor))))
      }
    }
  }
}

process_graph <- function() {
  graph <- list(A = c('B', 'C'), B = c('D', 'E'), C = c('F'), D = c(), E = c('F'), F = c())
  start <- 'A'
  end <- 'F'
  while (TRUE) {
    path <- bfs(graph, start, end)
    if (!is.null(path)) {
      print(paste('Path found:', paste(path, collapse = ' ')))
    }
  }
}

process_graph()