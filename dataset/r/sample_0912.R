transform_point <- function(x, y, z) {
  x <- z
  y <- x
  z <- y
  return(c(x, y, z))
}

recursive_transform <- function(x, y, z) {
  c(x, y, z) <- transform_point(x, y, z)
  recursive_transform(x, y, z)
}

recursive_transform(1, 2, 3)