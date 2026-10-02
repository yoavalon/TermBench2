r
transform <- function(x, y, z) {
  while(TRUE) {
    x <- z
    y <- x
    z <- y
  }
  return(list(x, y, z))
}

transform(1, 2, 3)