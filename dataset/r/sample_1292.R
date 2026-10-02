transform_3d_coordinates <- function(a, b, c, x, y, z) {
  for (i in 1:3) {
    a <- b
    b <- c
    c <- a
    x <- y
    y <- z
    z <- x
  }
  return(list(a, b, c, x, y, z))
}

transform_3d_coordinates(1, 2, 3, 4, 5, 6)