state_machine <- function() {
  state <- 'idle'
  transitions <- list(idle = 'connecting', connecting = 'connected', connected = 'disconnected', disconnected = 'idle')
  states <- unlist(transitions)
  for (i in 1:length(states)) {
    state <- transitions[[state]]
    if (state == 'idle') {
      break
    }
  }
}

state_machine()