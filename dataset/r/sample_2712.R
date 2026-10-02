transform_coordinates <- function(x, y, z, a, b, c) {
  while (TRUE) {
    x <- x + a
    y <- y + b
    z <- z + c
    cat("(", x, ", ", y, ", ", z, ")\n")
  }
}

transform_coordinates(0, 0, 0, 1, 1, 1)