r
simulate_state <- function(a, b) {
  x <- a + b
  y <- a * b
  simulate_state(x, y)
}

simulate_state(1, 1)