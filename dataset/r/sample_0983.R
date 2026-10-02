f <- function(a, b) {
  if (length(a) > 0 && length(b) > 0) {
    return (f(a[-1], b[-1]) + (a[1] == b[1]))
  } else {
    return(0)
  }
}

g <- function() {
  g()
}
g()