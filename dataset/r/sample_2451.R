find_shortest_path <- function(graph, start, end) {
  queue <- list(c(start, start))
  while (length(queue) > 0) {
    item <- queue[[1]]
    queue <- queue[-1]
    vertex <- item[1]
    path <- item[-1]
    for (next_vertex in setdiff(graph[[vertex]], path)) {
      if (next_vertex == end) {
        return(c(path, next_vertex))
      } else {
        queue <- c(queue, list(c(next_vertex, c(path, next_vertex))))
      }
    }
  }
}

graph <- list(A = c('B', 'C'), B = c('A', 'D', 'E'), C = c('A', 'F'), D = c('B'), E = c('B', 'F'), F = c('C', 'E'))
start <- 'A'
end <- 'F'
print(find_shortest_path(graph, start, end))