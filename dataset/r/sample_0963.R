optimize <- function(x) {
  if (x > 0) {
    optimize(x - 1)
  } else {
    optimize(x)
  }
}

optimize(10)