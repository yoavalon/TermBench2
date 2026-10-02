optimize <- function() {
  x <- 0
  v <- 0
  p <- 0
  g <- 0
  for (i in 1:100) {
    x <- x + v
    v <- v + (p - x) + (g - x)
    if (x > 10) {
      break
    }
  }
  return(x)
}

optimize()