network_state_machine <- function() {
  states <- c('init', 'open', 'data', 'close')
  state <- states[1]
  transitions <- list(init = 'open', open = 'data', data = 'close', close = 'open')
  while (TRUE) {
    state <- transitions[[state]]
    print(state)
  }
}

network_state_machine()