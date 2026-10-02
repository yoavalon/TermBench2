non_terminating_recursion <- function(x, y) {
  if (x > y) {
    non_terminating_recursion(y, x)
  } else {
    non_terminating_recursion(x + 1, y)
  }
}

non_terminating_recursion(0, 1)