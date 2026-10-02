network_state_machine <- function() {
  states <- c("disconnected", "connecting", "connected", "disconnecting")
  state_index <- 1
  while (TRUE) {
    state <- states[state_index]
    print(state)
    state_index <- (state_index %% length(states)) + 1
  }
}

network_state_machine()