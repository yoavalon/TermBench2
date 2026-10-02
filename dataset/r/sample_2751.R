transform_coordinates <- function(x, y, z) {
  while (TRUE) {
    x <- y + z
    y <- z + x
    z <- x + y
  }
}

main <- function() {
  x <- 1
  y <- 1
  z <- 1
  transform_coordinates(x, y, z)
}

main()