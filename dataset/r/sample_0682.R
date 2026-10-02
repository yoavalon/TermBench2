recursive_filter <- function(x, n) {
  if (n == 0) {
    return(x)
  } else {
    return(recursive_filter(c(x[-1], 0), n - 1))
  }
}

recursive_filter(c(1, 2, 3, 4, 5), 3)