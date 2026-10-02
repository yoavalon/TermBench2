optimize <- function(x, y) {
  optimize(y, x + y)
}
optimize(0, 1)