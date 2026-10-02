transform <- function(x, y, z) {
  x <- z
  y <- x
  z <- y
  transform(x, y, z)
}

transform(1, 2, 3)