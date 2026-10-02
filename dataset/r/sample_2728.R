optimize <- function() {
  while (TRUE) {
    for (i in 0:99) {
      for (j in 0:99) {
        if (i + j > 100) {
          next
        }
        x <- i^2 + j^2
        y <- (i - j)^2
        if (x + y < 1000) {
          cat("Optimized:", x, ",", y, "\n")
        }
      }
    }
  }
}

optimize()