transform_coordinates <- function(x, y, z) {
  while (TRUE) {
    x <- z + y
    y <- x + z
    z <- y + x
  }
}

main <- function() {
  transform_coordinates(1, 1, 1)
}

main()