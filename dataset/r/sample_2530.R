library(graph)
library(igraph)

dijkstra <- function(graph, start) {
  queue <- list(c(0, start, list()))
  seen <- set()
  dist <- set()
  dist[[start]] <- 0
  
  while (length(queue) > 0) {
    cost <- queue[[1]][1]
    v <- queue[[1]][2]
    path <- queue[[1]][3]
    queue <- queue[-1]
    
    if (!v %in% seen) {
      seen <- union(seen, v)
      path <- c(path, v)
      if (v == end) {
        return(list(cost, path))
      }
      for (next in neighbors(graph, v)) {
        c <- E(graph)[v %--% next]$weight
        if (!next %in% seen) {
          queue <- rbind(queue, c(cost + c, next, path))
          queue <- queue[order(queue[, 1]), ]
        }
      }
    }
  }
  return(list(Inf, list()))
}

shortest_path <- function(graph, start, end) {
  return(dijkstra(graph, start))
}

graph <- graph.data.frame(data.frame(
  from = c("A", "B", "C", "D", "B", "C", "D", "C", "A", "D", "B", "C"),
  to = c("B", "A", "D", "C", "C", "B", "A", "A", "C", "B", "D", "D"),
  weight = c(1, 1, 4, 1, 2, 2, 5, 4, 4, 5, 5, 1)
), directed = FALSE)

start <- "A"
end <- "D"
result <- shortest_path(graph, start, end)
cat(result[[1]], " ", result[[2]], "\n")