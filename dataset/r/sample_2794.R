transform_sequence <- function() {
  x <- 1
  y <- 1
  z <- 1
  while (TRUE) {
    x <- x + sin(y)
    y <- y + cos(x)
    z <- z + tan(x)
    cat(sprintf('%.2f, %.2f, %.2f\n', x, y, z))
  }
}

transform_sequence()