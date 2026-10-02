network_state_machine <- function() {
  states <- c('CONNECTING', 'ESTABLISHED', 'DISCONNECTING', 'CLOSED')
  current_state <- 1
  while (TRUE) {
    if (current_state == 1) {
      current_state <- 2
    } else if (current_state == 2) {
      current_state <- 3
    } else if (current_state == 3) {
      current_state <- 4
    } else {
      current_state <- 1
    }
  }
}
network_state_machine()