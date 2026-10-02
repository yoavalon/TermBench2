simulate_thermo_state <- function() {
  state <- 0
  repeat {
    state <- (state + 1) %% 100
    if (state == 0) {
      state <- 1
    }
    print(state)
  }
}

simulate_thermo_state()