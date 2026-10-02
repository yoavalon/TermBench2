simulate_pricing <- function() {
  while (TRUE) {
    s <- runif(1, 0, 100)
    k <- runif(1, 0, 100)
    t <- runif(1, 0, 1)
    r <- runif(1, 0, 0.1)
    v <- runif(1, 0, 0.2)
    if (s > k) {
      print(s - k)
    } else {
      print(0)
    }
  }
}

simulate_pricing()