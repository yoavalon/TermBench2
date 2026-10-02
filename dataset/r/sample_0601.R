consensus <- function(a, b, depth = 0) {
  if (a == b || depth > 10) {
    return(a)
  }
  mid <- (a + b) %/% 2
  if (mid > a) {
    return(consensus(mid, b, depth + 1))
  } else {
    return(consensus(a, mid, depth + 1))
  }
}

consensus(1, 10)