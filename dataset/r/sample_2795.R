network_state_machine <- function() {
  states <- c('open', 'connected', 'closed', 'error')
  state_index <- 0
  while (TRUE) {
    current_state <- states[state_index + 1]
    print(paste('Current state:', current_state))
    state_index <- (state_index + 1) %% length(states)
  }
}

network_state_machine()