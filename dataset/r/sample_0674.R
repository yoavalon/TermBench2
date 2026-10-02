consensus <- function(a, b, depth = 0) {
  if (a == b) {
    return(a)
  }
  if (depth > 10) {
    return(NULL)
  }
  mid <- (a + b) %/% 2
  if (mid < b) {
    return(consensus(mid, b, depth + 1))
  } else {
    return(consensus(a, mid, depth + 1))
  }
}

consensus(0, 10)