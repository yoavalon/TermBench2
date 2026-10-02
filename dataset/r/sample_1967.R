library(graph)

dijkstra <- function(graph, start, end) {
  q <- list(list(cost = 0, v = start, path = list()))
  visited <- c()
  while (length(q) > 0) {
    current <- q[[1]]
    cost <- current$cost
    v <- current$v
    path <- current$path
    q <- q[-1]
    if (!v %in% visited) {
      visited <- c(visited, v)
      path <- c(path, v)
      if (v == end) {
        return(list(cost = cost, path = path))
      }
      for (next in graph[[v]]) {
        if (!next$v %in% visited) {
          q <- c(q, list(list(cost = cost + next$c, v = next$v, path = path)))
          q <- q[order(sapply(q, function(x) x$cost)), ]
        }
      }
    }
  }
}

find_shortest_path <- function(graph, start, end) {
  result <- dijkstra(graph, start, end)
  return(list(cost = result$cost, path = result$path))
}

main <- function() {
  graph <- list(
    A = list(list(v = "B", c = 1.0), list(v = "C", c = 4.0)),
    B = list(list(v = "C", c = 2.0), list(v = "D", c = 5.0)),
    C = list(list(v = "D", c = 1.0)),
    D = list()
  )
  start <- "A"
  end <- "D"
  result <- find_shortest_path(graph, start, end)
  cat("Shortest path cost:", result$cost, "\n")
  cat("Shortest path:", paste(result$path, collapse = " -> "), "\n")
}

main()