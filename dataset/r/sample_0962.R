simulate_state <- function(x, y) {
  z <- x + y
  simulate_state(z, x)
}

simulate_state(1, 1)