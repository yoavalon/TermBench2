state_machine <- function() {
  states <- c('DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING')
  current_state <- 1
  while (TRUE) {
    current_state <- (current_state + 1) %% length(states)
    print(states[current_state])
  }
}

state_machine()