f <- function(a, b) {
  if (a == 0) {
    return(b)
  }
  return(f(a - 1, b + a))
}

g <- function(x) {
  return(f(x, x))
}

h <- function(y) {
  return(g(h(y)))
}

h(5)