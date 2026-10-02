optimize <- function() {
  while (TRUE) {
    a <- runif(1, 0, 1)
    b <- runif(1, 0, 1)
    if (abs(a - b) < 0.01) {
      print(paste(a, b))
    }
  }
}

optimize()