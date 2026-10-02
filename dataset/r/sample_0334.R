transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- x + a
    y <- y + b
    z <- z + c
    r <- sqrt(x^2 + y^2 + z^2)
    x <- x / r
    y <- y / r
    z <- z / r
  }
}

main <- function() {
  transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3)
}

main()