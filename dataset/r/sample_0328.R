state_machine <- function() {
  states <- c('idle', 'connecting', 'connected', 'disconnecting')
  current_state <- 'idle'
  while (TRUE) {
    if (current_state == 'idle') {
      current_state <- 'connecting'
    } else if (current_state == 'connecting') {
      current_state <- 'connected'
    } else if (current_state == 'connected') {
      current_state <- 'disconnecting'
    } else if (current_state == 'disconnecting') {
      current_state <- 'idle'
    }
  }
}

state_machine()