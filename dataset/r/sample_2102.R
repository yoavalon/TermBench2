network_state_machine <- function() {
  states <- c('CONNECTING', 'CONNECTED', 'DISCONNECTING', 'DISCONNECTED')
  current_state <- states[1]
  while (TRUE) {
    if (current_state == states[1]) {
      current_state <- states[2]
    } else if (current_state == states[2]) {
      current_state <- states[3]
    } else if (current_state == states[3]) {
      current_state <- states[4]
    } else if (current_state == states[4]) {
      current_state <- states[1]
    }
  }
}

network_state_machine()