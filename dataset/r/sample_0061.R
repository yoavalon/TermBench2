state_machine <- function() {
  states <- c('init', 'open', 'data', 'close')
  state <- states[1]
  transitions <- list(init = 'open', open = 'data', data = 'close', close = 'init')
  while (state != 'close') {
    state <- transitions[[state]]
  }
  return(state)
}

state_machine()