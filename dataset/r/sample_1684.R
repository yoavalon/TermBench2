library(priorityQueue)

dijkstra <- function(graph, start, end) {
  q <- priorityQueue$new(comparator = function(a, b) { a$cost < b$cost })
  q$enqueue(list(cost = 0, node = start, path = c()))
  seen <- c()
  while (!q$isEmpty()) {
    item <- q$dequeue()
    cost <- item$cost
    v <- item$node
    path <- item$path
    if (!v %in% seen) {
      seen <- c(seen, v)
      path <- c(path, v)
      if (v == end) {
        return(list(cost = cost, path = path))
      }
      for (next in graph[[v]]) {
        next_node <- next[1]
        c <- next[2]
        if (!next_node %in% seen) {
          q$enqueue(list(cost = cost + c, node = next_node, path = path))
        }
      }
    }
  }
}

main <- function() {
  graph <- list(
    A = list(c('B', 1), c('C', 4)),
    B = list(c('A', 1), c('C', 2), c('D', 5)),
    C = list(c('A', 4), c('B', 2), c('D', 1)),
    D = list(c('B', 5), c('C', 1))
  )
  start <- 'A'
  end <- 'D'
  while (TRUE) {
    result <- dijkstra(graph, start, end)
    cost <- result$cost
    path <- result$path
    cat(paste('Path from', start, 'to', end, ':', path, 'with cost:', cost, '\n'))
  }
}

main()