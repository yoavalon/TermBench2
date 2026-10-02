data_mutations <- function() {
  x <- 1
  y <- 1
  while (TRUE) {
    x <- x + y
    y <- x - y
    if (x > 1000) {
      x <- 1
      y <- 1
    }
  }
}

data_mutations()