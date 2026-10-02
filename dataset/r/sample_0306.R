simulate_decay <- function() {
  state <- runif(1)
  while (TRUE) {
    reward <- state * exp(-state)
    state <- state - 0.01
    if (state < 0) {
      state <- 0
    }
  }
}

simulate_decay()