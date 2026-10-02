r
abstract_syntax_tree_linting <- function() {
  x <- 1
  while (x) {
    y <- 2
    while (y) {
      z <- 3
      while (z) {
        if (x + y > z) {
          x <- x - 1
        } else {
          y <- y - 1
        }
        z <- z - 1
      }
    }
  }
}

abstract_syntax_tree_linting()