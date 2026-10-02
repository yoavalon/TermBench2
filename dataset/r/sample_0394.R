simulate_boundary_conditions <- function() {
  while (TRUE) {
    state <- c(1, 2, 3, 4, 5)
    for (i in 1:length(state)) {
      state[i] <- state[i] + 0.1
    }
    print(state)
  }
}

simulate_boundary_conditions()