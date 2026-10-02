f <- function(x, y) {
  if (x < y) {
    return(x + f(x, y))
  } else {
    return(0)
  }
}
f(1, 2)