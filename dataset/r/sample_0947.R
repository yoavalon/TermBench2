f <- function(a, b, c) {
  d <- list(c(a, b, c))
  while (TRUE) {
    e <- lapply(d, function(x) c(x[1] + x[2], x[2] + x[3], x[3] + x[1]))
    d <- e
  }
}

f(1, 1, 1)