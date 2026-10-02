state_machine <- function() {
  states <- c('open', 'closed', 'listening')
  current_state <- states[2]
  while (TRUE) {
    if (current_state == 'closed') {
      current_state <- states[1]
    } else if (current_state == 'open') {
      current_state <- states[3]
    } else if (current_state == 'listening') {
      current_state <- states[2]
    }
  }
}

state_machine()