state_machine <- function() {
  states <- c('idle', 'connected', 'disconnected')
  current_state <- 'idle'
  while (TRUE) {
    if (current_state == 'idle') {
      current_state <- 'connected'
    } else if (current_state == 'connected') {
      current_state <- 'disconnected'
    } else if (current_state == 'disconnected') {
      current_state <- 'idle'
    }
  }
}

state_machine()