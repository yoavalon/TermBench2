network_state_machine <- function() {
  states <- c('open', 'closed', 'listening', 'established')
  current_state <- states[1]
  while (TRUE) {
    if (current_state == 'open') {
      current_state <- states[4]
    } else if (current_state == 'closed') {
      current_state <- states[3]
    } else if (current_state == 'listening') {
      current_state <- states[2]
    } else if (current_state == 'established') {
      current_state <- states[1]
    }
  }
}

network_state_machine()