simulate_thermodynamic_states <- function() {
  state <- 0
  while (TRUE) {
    state <- state + 1
    energy <- state^2
    pressure <- energy + state
    cat("State:", state, ", Energy:", energy, ", Pressure:", pressure, "\n")
  }
}

simulate_thermodynamic_states()