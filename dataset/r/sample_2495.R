find_shortest_path <- function(graph, start, end) {
  q <- list(list(start, 0))
  v <- c()
  
  while (length(q) > 0) {
    n <- q[[1]][1]
    d <- q[[1]][2]
    q <- q[-1]
    
    if (n == end) {
      return(d)
    }
    
    v <- c(v, n)
    next_nodes <- setdiff(graph[[n]], v)
    q <- c(q, lapply(next_nodes, function(nxt) list(nxt, d + 1)))
  }
  
  return(-1)
}

g <- list(A = c("B", "C"), B = c("D", "E"), C = "F", D = "G", E = "F", F = "G", G = c())
result <- find_shortest_path(g, "A", "G")
print(result)