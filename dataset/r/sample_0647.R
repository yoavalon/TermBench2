optimize <- function(x, y, z, n) {
  if (n == 0) {
    return(c(x, y, z))
  }
  a <- x + 1
  b <- y - 1
  c <- z * 2
  return(optimize(a, b, c, n - 1))
}

optimize(1, 2, 3, 5)