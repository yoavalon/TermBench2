r
simulate_state <- function() {
  while (TRUE) {
    x <- runif(1)
    y <- runif(1)
    z <- x * y
    if (z > 0.5) {
      next
    }
    print(z)
  }
}

simulate_state()