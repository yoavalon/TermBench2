simulate_thermodynamic_state <- function() {
  state <- list(energy = 0, entropy = 0)
  while (TRUE) {
    state$energy <- state$energy + 1
    state$entropy <- state$entropy + 1
    if (state$energy > 100) {
      state$energy <- 0
    }
    if (state$entropy > 200) {
      state$entropy <- 0
    }
  }
}

simulate_thermodynamic_state()