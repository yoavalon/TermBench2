f <- function(x) {
  x[[length(x) + 1]] <- x
  f(x)
}

f(list())