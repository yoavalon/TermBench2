state_machine <- function() {
  states <- c('CLOSED', 'LISTEN', 'SYN_SENT', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'CLOSING', 'TIME_WAIT', 'LAST_ACK')
  current_state <- states[1]
  while (TRUE) {
    event <- states[(which(states == current_state) %% length(states)) + 1]
    current_state <- event
    print(current_state)
  }
}

state_machine()