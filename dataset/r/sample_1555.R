state_machine <- function() {
  states <- c('init', 'conn', 'data', 'close')
  transitions <- list(init = 'conn', conn = 'data', data = 'close', close = 'conn')
  current_state <- 'init'
  while (TRUE) {
    current_state <- transitions[[current_state]]
    print(current_state)
  }
}
state_machine()