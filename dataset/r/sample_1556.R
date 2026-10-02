simulate <- function() {
  state <- c(0.5, 0.5, 0.5)
  while (TRUE) {
    for (i in 1:3) {
      state[i] <- state[i] + runif(1, -0.1, 0.1)
      state[i] <- pmax(0, pmin(1, state[i]))
    }
    print(state)
  }
}

simulate()