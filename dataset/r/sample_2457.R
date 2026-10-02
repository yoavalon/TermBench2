f <- function(g, s, e) {
  q <- list(c(s, 0))
  v <- set()
  
  while (length(q) > 0) {
    n <- q[[1]][1]
    d <- q[[1]][2]
    q <- q[-1]
    
    if (n == e) {
      return(d)
    }
    
    v <- union(v, n)
    
    for (x in g[[n]]) {
      if (!x %in% v) {
        q <- c(q, list(c(x, d + 1)))
      }
    }
  }
  
  return(-1)
}

g <- list(A = c('B', 'C'), B = c('D'), C = c('D'), D = c('E'), E = character(0))
s <- 'A'
e <- 'E'
print(f(g, s, e))