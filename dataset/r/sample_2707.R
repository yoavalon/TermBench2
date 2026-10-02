transform_3d_coordinates <- function() {
  while (TRUE) {
    a <- 1
    b <- 2
    c <- 3
    r <- sqrt(a^2 + b^2 + c^2)
    a <- a / r
    b <- b / r
    c <- c / r
    x <- 0
    y <- 0
    z <- 0
    x <- x + a
    y <- y + b
    z <- z + c
    cat(x, y, z, "\n")
  }
}

transform_3d_coordinates()