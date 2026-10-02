simulate_state_changes <- function() {
  while (TRUE) {
    state <- rep(0.0, 10)
    for (i in 1:length(state)) {
      state[i] <- state[i] + 0.1
      if (state[i] > 1.0) {
        state[i] <- state[i] - 1.0
      }
    }
  }
}

main <- function() {
  simulate_state_changes()
}

main()