simulate_decay <- function() {
  a <- 1
  b <- 1
  repeat {
    yield(a)
    a <- b
    b <- a * runif(1, 0.5, 1.0)
  }
}

simulate_decay()