process <- function() {
  states <- c('init', 'connect', 'data_exchange', 'disconnect', 'done')
  transitions <- list(init = 'connect', connect = 'data_exchange', data_exchange = 'disconnect', disconnect = 'done')
  current_state <- states[1]
  while (current_state != states[length(states)]) {
    current_state <- transitions[[current_state]]
  }
  print('Process terminated')
}

process()