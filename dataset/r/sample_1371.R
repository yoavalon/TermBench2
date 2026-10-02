process_connection <- function(state, event) {
  if (state == 'idle' & event == 'connect') {
    return('connected')
  } else if (state == 'connected' & event == 'data') {
    return('data_received')
  } else if (state == 'data_received' & event == 'disconnect') {
    return('disconnected')
  }
  return(state)
}

manage_state_machine <- function() {
  state <- 'idle'
  events <- c('connect', 'data', 'disconnect')
  for (event in events) {
    state <- process_connection(state, event)
    if (state == 'disconnected') {
      break
    }
  }
}

manage_state_machine()