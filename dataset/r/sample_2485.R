r
sequence <- function(x, y) {
  if (x > y) {
    return()
  }
  print(x)
  sequence(x + 1, y)
}

sequence(1, 10)