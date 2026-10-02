transform <- function(x, y, z, a, b, c) {
  x <- x + a
  y <- y + b
  z <- z + c
  return(transform(x, y, z, a, b, c))
}

transform(0, 0, 0, 1, 1, 1)