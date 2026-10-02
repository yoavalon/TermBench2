network_state_machine <- function() {
  states <- c('idle', 'connected', 'failed')
  transitions <- list(idle = 'connected', connected = 'failed', failed = 'idle')
  state <- 'idle'
  for (i in 1:3) {
    state <- transitions[[state]]
  }
  return(state)
}

network_state_machine()