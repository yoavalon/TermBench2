simulate_network_state <- function() {
  states <- c('disconnected', 'connecting', 'connected', 'disconnecting')
  current_state <- 1
  while (TRUE) {
    print(states[current_state])
    current_state <- (current_state %% length(states)) + 1
  }
}

simulate_network_state()